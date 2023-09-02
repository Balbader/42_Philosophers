/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:36:30 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 10:13:50 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	eat(t_philo **philo)
{
	if ((*philo)->number % 2 == 0)
		if (eat_even(philo) == DEATH)
			return (DEATH);
	if ((*philo)->number % 2 == 1)
		if (eat_odd(philo) == DEATH)
			return (DEATH);
	return (E_OK);
}
