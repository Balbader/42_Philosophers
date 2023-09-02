/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:44:40 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 09:44:42 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	ft_end(t_rules *r, int i, int state)
{
	int	full_philos;

	full_philos = 0;
	while (1)
	{
		i = 0;
		if (ft_check_health(r) == 0)
			break ;
		while (i < r->nb_philo)
		{
			state = ft_check_vitals(r, i);
			if (state == 1)
				break ;
			else if (state == 2)
				full_philos++;
			if (full_philos == r->nb_philo)
			{
				pthread_mutex_lock(&(r->health_check));
				r->all_ate = 1;
				pthread_mutex_unlock(&(r->health_check));
			}
			i++;
		}
	}
	usleep(200);
}
