/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:03:41 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 15:49:12 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	timestamp_init(t_args *data)
{
	gettimeofday(&(data->current_time), NULL);
	data->timestamp = data->current_time.tv_usec;
	data->timestamp_seconds = data->current_time.tv_sec;
}

static int	free_memory(t_args *data, t_philo **philo)
{
	if (!data->death || !data->meals || !(*philo) || !data->threads
		|| !data->forks_mutex || !data->death_mutex)
	{
		if (data->death)
			free (data->death);
		if (data->meals)
			free (data->meals);
		if (data->threads)
			free (data->threads);
		if (data->forks_mutex)
			free (data->forks_mutex);
		if (data->death_mutex)
			free (data->death_mutex);
		if (*philo)
			free (*philo);
		return (E_MALLOC);
	}
	return (E_OK);
}

static int	memory_allocation(t_args *data, t_philo **philo)
{
	data->death = NULL;
	data->meals = NULL;
	*philo = NULL;
	data->threads = NULL;
	data->forks_mutex = NULL;
	data->death_mutex = NULL;
	data->death = malloc(sizeof(int) * data->nb_philo);
	data->meals = malloc(sizeof(int) * data->nb_philo);
	*philo = malloc(sizeof(t_philo) * data->nb_philo);
	data->threads = malloc(sizeof(pthread_t) * (data->nb_philo));
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * (data->nb_philo));
	data->death_mutex = malloc(sizeof(pthread_mutex_t));
	if (free_memory(data, philo) == E_MALLOC)
		return (ft_putstr_fd("memory allocation failed\n", 2), E_MALLOC);
	return (E_OK);
}

static void	data_fulfill(t_args *data, t_philo **philo, int meals)
{
	data->i = -1;
	while (++data->i < data->nb_philo)
	{
		(*philo)[data->i].last_meal = getime(data);
		(*philo)[data->i].number = data->i + 1;
		(*philo)[data->i].data = data;
		if (data->i == 0)
			(*philo)[data->i].left_fork = \
			&(data->forks_mutex[data->nb_philo - 1]);
		else
			(*philo)[data->i].left_fork = &(data->forks_mutex[data->i - 1]);
		(*philo)[data->i].right_fork = &(data->forks_mutex[data->i]);
		data->death[data->i] = 0;
		data->meals[data->i] = meals;
	}
}

int	init(t_args *data, char **av, int ac, t_philo **philo)
{
	int	meals;

	if (ac == 6)
		meals = ft_atoi(av[5]);
	else
		meals = 10;
	data->ac = ac;
	data->nb_philo = ft_atoi(av[1]);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (memory_allocation(data, philo) == E_MALLOC)
		return (E_MALLOC);
	timestamp_init(data);
	data_fulfill(data, philo, meals);
	mutex_init(philo, data);
	return (E_OK);
}
