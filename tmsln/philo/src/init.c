/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:50:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/03/30 15:30:05 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philos(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philos[i].id = i + 1;
		rules->philos[i].right_fork_idx = i;
		if (rules->nb_philo > 1)
			rules->philos[i].left_fork_idx = (i + 1) % rules->nb_philo;
		else
			rules->philos[i].left_fork_idx = -1;
		rules->philos[i].last_meal = 0;
		rules->philos[i].nb_meal = 0;
		rules->philos[i].rules = rules;
		rules->philos[i].hunger = 1;
		i++;
	}
	return (0);
}

int	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (write(2, "Error:\nIssue creating mutex.\n", 29));
		i++;
	}
	if (pthread_mutex_init(&(rules->printing), NULL))
		return (write(2, "Error:\nIssue creating mutex.\n", 29));
	if (pthread_mutex_init(&(rules->health_check), NULL))
		return (write(2, "Error:\nIssue creating mutex.\n", 29));
	return (0);
}

int	init_sim(t_rules *rules, char **av)
{
	rules->nb_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->dead_end = 0;
	rules->all_ate = 0;
	if (rules->nb_philo < 1 || rules->nb_philo > 200 || rules->time_to_die < 1
		|| rules->time_to_eat < 1 || rules->time_to_sleep < 1)
		return (write(2, "Error:\nSome args aren't valid\n", 31));
	if (av[5])
	{
		rules->x_meal = ft_atoi(av[5]);
		if (rules->x_meal <= 0)
			return (write(2, "Error:\nPhilos have to eat once at least.\n", 41));
	}
	else
		rules->x_meal = -1;
	if (init_mutex(rules))
		return (1);
	if (init_philos(rules))
		return (1);
	return (0);
}
