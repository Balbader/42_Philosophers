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

int	ft_init_dinner(t_config *conf, char **av)
{
	conf->nb_philo = ft_atoi(av[1]);
	conf->time_to_die = ft_atoi(av[2]);
	conf->time_to_eat = ft_atoi(av[3]);
	conf->time_to_sleep = ft_atoi(av[4]);
	conf->dead_end = 0;
	conf->all_ate = 0;
	if (conf->nb_philo < 1 || conf->nb_philo > 200 || conf->time_to_die < 1
		|| conf->time_to_eat < 1 || conf->time_to_sleep < 1)
		ft_putstr_fd(ARG_ERR, 2);
	if (av[5])
	{
		conf->x_meal = ft_atoi(av[5]);
		if (conf->x_meal <= 0)
			ft_putstr_fd(MEAL_ERR, 2);
	}
	else
		conf->x_meal = -1;
	if (ft_init_mutex(conf))
		return (1);
	if (ft_init_philosophers(conf))
		return (1);
	return (0);
}
