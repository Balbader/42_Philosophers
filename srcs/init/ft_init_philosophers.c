/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:00:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:00:09 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * initiate the configuration of each philosopher
*/

int	ft_init_philosophers(t_config *conf)
{
	int	i;

	i = 0;
	while (i < conf->nb_philo)
	{
		conf->philos[i].id = i + 1;
		if (conf->philos[i].id % 2 == 0)
		{
			conf->philos[i].right_fork_idx = i;
			conf->philos[i].left_fork_idx = (i + 1) % conf->nb_philo;
		}
		else
		{
			conf->philos[i].right_fork_idx = (i + 1) % conf->nb_philo;
			conf->philos[i].left_fork_idx = i;
		}
		conf->philos[i].last_meal = 0;
		conf->philos[i].meal_count = 0;
		conf->philos[i].config = conf;
		conf->philos[i].hungry = 1;
		i++;
	}
	return (0);
}
