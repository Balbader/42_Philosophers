/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:06:12 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:06:14 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_init_dinner(t_rules *rules, char **av)
{
	rules->nb_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->dead_end = 0;
	rules->all_ate = 0;
	if (rules->nb_philo < 1 || rules->nb_philo > 200 || rules->time_to_die < 1
		|| rules->time_to_eat < 1 || rules->time_to_sleep < 1)
		ft_putstr_fd(ARG_ERR, 2);
	if (av[5])
	{
		rules->x_meal = ft_atoi(av[5]);
		if (rules->x_meal <= 0)
		ft_putstr_fd(MEAL_ERR, 2);
	}
	else
		rules->x_meal = -1;
	if (ft_init_mutex(rules))
		return (1);
	if (ft_init_philosophers(rules))
		return (1);
	return (0);
}
