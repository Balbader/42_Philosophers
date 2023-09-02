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

void	*ft_threader(void *void_philo)
{
	t_philo	*p;
	t_rules	*r;

	p = (t_philo *)void_philo;
	r = p->rules;
	if (r->nb_philo == 1)
		return (ft_philo_alone(r, p));
	if (p->id % 2 == 0)
		ft_usleep(r->time_to_eat);
	while (1)
	{
		if (ft_check_health(r) == 0)
			break ;
		pthread_mutex_lock(&(r->forks[p->right_fork_idx]));
		ft_print_state(p, r, FORK);
		pthread_mutex_lock(&(r->forks[p->left_fork_idx]));
		ft_print_state(p, r, FORK);
		ft_is_eating(r, p);
		pthread_mutex_unlock(&(r->forks[p->right_fork_idx]));
		pthread_mutex_unlock(&(r->forks[p->left_fork_idx]));
		ft_print_state(p, r, SLEEPING);
		ft_usleep(r->time_to_sleep);
		ft_print_state(p, r, THINKING);
	}
	return (0);
}
