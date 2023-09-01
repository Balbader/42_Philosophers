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

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	int			nb_philo;
	t_config	config;
	t_dinner	dinner_setup;
	t_philo		*philosophers;

	if (!ft_parse_config(ac, av, &config))
		return (ERROR);
	nb_philo = config.nb_philo;
	if (!ft_init_mutexes(&dinner_setup.mutexes, nb_philo))
		return (ERROR);
	ft_setup_dinner(&dinner_setup);
	if (!ft_init_philosophers(&philosophers, nb_philo, &dinner_setup, &config))
		return (ft_clean_exit(&dinner_setup, NULL, nb_philo, ERROR));
	if (!ft_start_dinner(&dinner_setup, philosophers, nb_philo))
		return (ft_clean_exit(&dinner_setup, philosophers, nb_philo, ERROR));
	if (config.min_nb_meal >= 0)
		ft_check_meal_count(philosophers, nb_philo, config.min_nb_meal);
	ft_clean_exit(&dinner_setup, philosophers, nb_philo, 0);
	return (0);
}
