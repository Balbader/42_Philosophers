/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:32:23 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 10:32:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 *
*/

void	*ft_dinner(void *arg)
{
	t_philo			*philo;
	time_t			time;
	time_t			think_delay;

	philo = (t_philo *)arg;
	while (!*philo->is_dinner_over && philo->min_nb_meal != 0)
	{
		if (philo->min_nb_meal > 0 && philo->nb_meal >= philo->min_nb_meal)
			ft_usleep(1000);
		if (!ft_eat(philo))
			break ;
		if (philo->nb_meal < INT_MAX)
			philo->nb_meal++;
		time = ft_get_time();
		if (!ft_print_state(philo, time, SLEEP))
			break ;
		think_delay = ft_get_time() - time;
		if (!*philo->is_dinner_over && think_delay < philo->time_to_sleep)
			ft_usleep((philo->time_to_sleep - think_delay) * 1000);
		if (!ft_print_state(philo, ft_get_time(), THINK))
			break ;
	}
	return (arg);
}
