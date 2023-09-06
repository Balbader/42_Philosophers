/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:49:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:49:49 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * This is where the magic happens
 * this function will run the entire dinner
*/

static void	ft_run_loop(t_config *conf, t_philo *philo)
{
	while (1)
	{
		if (ft_check_health(conf) == 0)
			break ;
		pthread_mutex_lock(&(conf->forks[philo->right_fork_idx]));
		ft_print_state(philo, conf, FORK);
		pthread_mutex_lock(&(conf->forks[philo->left_fork_idx]));
		ft_print_state(philo, conf, FORK);
		ft_is_eating(conf, philo);
		pthread_mutex_unlock(&(conf->forks[philo->right_fork_idx]));
		pthread_mutex_unlock(&(conf->forks[philo->left_fork_idx]));
		ft_print_state(philo, conf, SLEEPING);
		ft_usleep(conf->time_to_sleep);
		ft_print_state(philo, conf, THINKING);
		usleep(100);
	}
}

void	*ft_threader(void *void_philo)
{
	t_philo		*philo;
	t_config	*conf;

	philo = (t_philo *)void_philo;
	conf = philo->config;
	if (conf->nb_philo == 1)
		return (ft_philo_alone(conf, philo));
	if (philo->id % 2 == 0)
		ft_usleep(conf->time_to_eat);
	ft_run_loop(conf, philo);
	return (0);
}
