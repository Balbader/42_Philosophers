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

int	ft_init_philosophers(t_rules *rules)
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
