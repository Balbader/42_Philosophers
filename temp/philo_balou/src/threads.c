/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:06:20 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 11:25:49 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->number % 2 == 0)
		usleep(1000);
	while (is_dead(philo) != DEATH && philo->data->meals[philo->number - 1] > 0)
	{	
		if (eat(&philo) == DEATH || mysleep(philo) == DEATH)
			return (NULL);
	}
	return (NULL);
}
