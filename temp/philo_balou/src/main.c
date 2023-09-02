/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:37:16 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 16:07:06 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	error_management(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5)
		return (ft_putstr_fd("not enough arguments\n", 2), ERROR);
	if (ac > 6)
		return (ft_putstr_fd("too many arguments\n", 2), ERROR);
	if (ft_atoi(av[1]) < 1)
		return (ft_putstr_fd("1 philosopher minimum\n", 2), ERROR);
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0 || (ac == 6 && ft_atoi(av[5]) < 0))
		return (ft_putstr_fd("Program can not work with negative values\n", 2), \
		ERROR);
	while (++i < ac && av[i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] != '+' && av[i][j] != '-' && ft_isdigit(av[i][j]) == 0)
				return (ft_putstr_fd(\
				"only digits and + or - operands allowed\n", 2), ERROR);
	}
	return (E_OK);
}

static void	satiated(t_args *data, t_philo **philo, int *stop)
{
	int	j;

	j = 0;
	while ((*philo)[j].data->meals[(*philo)[j].number - 1] == 0)
	{
		j++;
		if (j == (*philo)[0].data->nb_philo)
		{
			*stop = 1;
			pthread_mutex_unlock(&data->print_mutex);
			break ;
		}
	}
	if (*stop != 1)
		pthread_mutex_unlock(&data->print_mutex);
}

static void	death_procedure(t_args *data, t_philo **philo, int *stop, int *i)
{
	pthread_mutex_lock((*philo)[*i].data->death_mutex);
	(*philo)[*i].data->death[0] = DEATH;
	pthread_mutex_unlock((*philo)[*i].data->death_mutex);
	ft_printf(PURPLE"%d %d died\n", (int)getime((*philo)[*i].data), \
	(*philo)[*i].number);
	pthread_mutex_unlock(&data->print_mutex);
	*stop = 1;
}

static void	supervisor(t_args *data, t_philo **philo)
{
	int	i;
	int	stop;

	stop = 0;
	while (1)
	{
		i = -1;
		while (stop != 1 && ++i < data->nb_philo)
		{
			pthread_mutex_lock(&data->print_mutex);
			if (getime(data) - (*philo)[i].last_meal >= (*philo)[i].data->die
				&& (*philo)[i].data->meals[(*philo)[i].number - 1] > 0)
				death_procedure(data, philo, &stop, &i);
			else
				satiated(data, philo, &stop);
		}
		usleep(9000);
		if (stop == 1)
			break ;
	}
}

int	main(int ac, char **av)
{
	int			i;
	int			error_status;
	t_args		data;
	t_philo		*philo;

	if (error_management(ac, av) != E_OK)
		return (ERROR);
	error_status = init(&data, av, ac, &philo);
	if (error_status != E_OK)
		return (error_status);
	i = -1;
	philo->last_meal = getime(&data);
	while (++i < data.nb_philo)
		pthread_create(data.threads + i, NULL, thread, &philo[i]);
	supervisor(&data, &philo);
	i = -1;
	while (++i < data.nb_philo)
		if (pthread_join(data.threads[i], NULL) != 0)
			return (ft_putstr_fd("join failed\n", 2), ERROR);
	free_all(&data, &philo);
	return (E_OK);
}
