/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:44:45 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:44:46 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	ft_is_eating(t_rules *r, t_philo *p)
{
	pthread_mutex_lock(&(r->health_check));
	p->last_meal = ft_get_time();
	p->nb_meal++;
	pthread_mutex_unlock(&(r->health_check));
	ft_print_state(p, r, "is eating");
	ft_usleep(r->time_to_eat);
}
