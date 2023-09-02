/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:44:50 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:44:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	ft_print_state(t_philo *p, t_rules *r, char *action)
{
	pthread_mutex_lock(&(r->printing));
	if (ft_check_health(r) == 0 && action[0] != 'd')
	{
		pthread_mutex_unlock(&(r->printing));
		return ;
	}
	printf("%ld %d %s\n", ft_time_diff(ft_get_time(), r->start), p->id, action);
	pthread_mutex_unlock(&(r->printing));
}
