/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:14:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 18:14:16 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_clean_exit(t_diner *diner_setup, t_philo *philosophers, int nb_philo, int ret_val)
{
	int		i;

	if (diner_setup->philo_threads)
	{
		i = 0;
		while (i < nb_philo)
		{
			pthread_join(diner_setup->philo_threads[i], NULL);
			pthread_join(diner_setup->philo_monitors[i++], NULL);
		}
	}
	clean_mutexes(&diner_setup->mutexes, nb_philo);
	if (diner_setup->philo_threads)
		free(diner_setup->philo_threads);
	if (diner_setup->philo_monitors)
		free(diner_setup->philo_monitors);
	if (philosophers)
		free(philosophers);
	return (ret_val);
}