/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_alone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:54:23 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:54:25 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * In case there is only one philosopher :
 * . Lock the thread
 * . make him pick up a fork
 * . unlock the thread so he can die in peace
*/

void	*ft_philo_alone(t_config *conf, t_philo *philo)
{
	pthread_mutex_lock(&(conf->forks[philo->right_fork_idx]));
	ft_print_state(philo, conf, FORK);
	pthread_mutex_unlock(&(conf->forks[philo->right_fork_idx]));
	return (0);
}
