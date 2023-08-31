/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:10:20 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 16:10:22 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_bool	ft_init_philosophers(t_philo **philosophers, int nb_philo,
		t_dinner *dinner_setup, t_config *config)
{
	int	i;

	*philosophers = malloc(nb_philo * sizeof(t_philo));
	if (!*philosophers)
		return (ft_print_err(PHILO_ALLOC, NULL, FALSE));
	i = 0;
	while (i < nb_philo)
	{
		ft_setup_philosophers(&(*philosophers)[i], i, dinner_setup, config);
		i++;
	}
	return (TRUE);
}
