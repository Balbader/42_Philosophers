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

void	*ft_philo_alone(t_rules *r, t_philo *p)
{
	pthread_mutex_lock(&(r->forks[p->right_fork_idx]));
	ft_print_state(p, r, "has taken a fork");
	pthread_mutex_unlock(&(r->forks[p->right_fork_idx]));
	return (0);
}
