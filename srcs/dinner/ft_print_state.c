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

/*
 * 	locks the printing thread
 * 	checks if all philosophers have eaten of if a philosopher died
 *	if not will print the current state of each philo.
 *	unlock the thread
*/

void	ft_print_state(t_philo *philo, t_config *conf, char *state)
{
	pthread_mutex_lock(&(conf->printing));
	if (ft_check_health(conf) == 0 && state[0] != 'd')
	{
		pthread_mutex_unlock(&(conf->printing));
		return ;
	}
	printf("%ld %d %s\n", ft_time_diff(ft_get_time(),
			conf->start), philo->id, state);
	pthread_mutex_unlock(&(conf->printing));
}
