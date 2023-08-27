/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:15:21 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 17:15:23 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int			nb_philo;
	t_config	config;
	t_diner		diner_setup;
	t_philo		*philosophers;

	if (!ft_parse_config(ac, av, &config))
		return (ERROR);
	nb_philo = config.nb_philo;
	if (!ft_init_mutexes(&diner_setup.mutexes, nb_philo))
		return (ERROR);
	ft_setup_dinner(&diner_setup);
	if (!ft_init_philosophers(&philosophers, nb_philo, &diner_setup, &config))
		return (ft_clean_exit(&diner_setup, NULL, nb_philo, ERROR));
	if (!ft_start_diner(&diner_setup, philosophers, nb_philo))
		return (ft_clean_exit(&diner_setup, philosophers, nb_philo, ERROR));
	if (config.min_nb_meal >= 0)
		ft_check_meal_count(philosophers, nb_philo, config.min_nb_meal);
	ft_clean_exit(&diner_setup, philosophers, nb_philo, 0);
	return (0);
}
