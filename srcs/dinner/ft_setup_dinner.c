/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:56:27 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 11:56:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * file		:	init.c
 * function	:	void init_diner_setup(t_diner *diner_setup);
*/

void	ft_setup_dinner(t_diner *dinner_setup)
{
	diner_setup->philo_threads = NULL;
	diner_setup->philo_monitors = NULL;
	diner_setup->is_dinner_over = FALSE;
}
