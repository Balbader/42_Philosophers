/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:02:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 17:02:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

/*
 * Parse and assign the given data to run the simulation for :
 * nb of philo
 * nb of meals
 * returns True is parsing and assignment are successful
 * returns False if not
*/

t_bool	ft_parse_config(int ac, char **av, t_config *config)
{
	char	*str;

	if (ac != 5 && ac != 6)
		return (ft_print_err(WRONG_ARGC1, WRONG_ARGC2, FALSE));
	str = av[1] + (*av[1] == '+') - 1;
	while (*++str)
		if (*str < '0' || *str > '9')
			return (ft_print_err(WRONG_NB1, WRONG_NB2, FALSE));
	config->nb_philo = ft_atoi_long(av[1]);
	if (config->nb_philo < 1 || config->nb_philo > INT_MAX)
		return (ft_print_err(WRONG_NB1, WRONG_NB2, FALSE));
	if (!ft_parse_times(av, config))
		return (ft_print_err(WRONG_TIME1, WRONG_TIME2, FALSE));
	config->min_nb_meal = -1;
	if (ac == 6)
	{
		str = av[5] + (*av[5] == '+') - 1;
		while (*++str)
			if (*str < '0' || *str > '9')
				return (ft_print_err(WRONG_MEAL1, WRONG_MEAL2, FALSE));
		config->min_nb_meal = ft_atoi_long(av[5]);
		if (config->min_nb_meal < 0 || config->min_nb_meal > INT_MAX)
			return (ft_print_err(WRONG_MEAL1, WRONG_MEAL2, FALSE));
	}
	return (TRUE);
}
