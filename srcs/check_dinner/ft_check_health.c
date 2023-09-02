/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_health.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:26:09 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:26:11 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_check_health(t_rules *r)
{
	int	i;

	pthread_mutex_lock(&(r->health_check));
	if (r->all_ate || r->dead_end)
		i = 0;
	else
		i = 1;
	pthread_mutex_unlock(&(r->health_check));
	return (i);
}
