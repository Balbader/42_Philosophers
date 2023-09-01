/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_meal_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:24:00 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 16:24:05 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 *  
*/

void	ft_check_meal_count(t_philo *philosophers, int nb_philo,
		int min_nb_meal)
{
	int			i;
	t_philo		*philo;

	while (!*philosophers[0].is_dinner_over)
	{
		i = 0;
		while (i < nb_philo)
		{
			philo = &philosophers[i];
			if (philo->nb_meal < min_nb_meal)
				break ;
			if ((i + 1) == nb_philo)
			{
				ft_is_thinking(philo, ft_get_time(), MIN_NB_MEAL);
				*philo->is_dinner_over = TRUE;
				return ;
			}
			i++;
		}
		ft_usleep(1000);
	}
}
