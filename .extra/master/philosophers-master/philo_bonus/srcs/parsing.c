/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/13 11:56:17 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philo_parsing.h"

#define WRONG_ARGC1	"You must provide the 4 required arguments"
#define WRONG_ARGC2	" (or 5 with the nb_of_meal)"
#define WRONG_NB1	"The number of philosophers must be"
#define WRONG_NB2	" a valid integer between 1 and INT_MAX"
#define WRONG_TIME1	"The times (in milliseconds) must be"
#define WRONG_TIME2	" valid integers between 0 and INT_MAX"
#define WRONG_MEAL1	"The nb_of_meal must be"
#define WRONG_MEAL2	" a valid integer between 0 and INT_MAX"

static long	ft_atoi_strict(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str++ - '0';
		if (sign < 0 && (-nb) < INT_MIN)
			return (LONG_MIN);
		if (sign > 0 && nb > INT_MAX)
			return (LONG_MAX);
	}
	return (nb * sign);
}

static t_bool	record_times(char *argv[], t_config *config)
{
	static int	i = 2;
	char		*str;
	long		time;	

	str = argv[i] + (*argv[i] == '+');
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (FALSE);
		str++;
	}
	time = ft_atoi_strict(argv[i]);
	if (time > INT_MAX)
		return (FALSE);
	if (i == 2)
		config->time_to_die = time;
	else if (i == 3)
		config->time_to_eat = time;
	else
		config->time_to_sleep = time;
	if (i++ < 4)
		return (record_times(argv, config));
	return (TRUE);
}

t_bool	parse_config(int argc, char *argv[], t_config *config)
{
	char	*str;

	if (argc != 5 && argc != 6)
		return (print_error(WRONG_ARGC1, WRONG_ARGC2, FALSE));
	str = argv[1] + (*argv[1] == '+') - 1;
	while (*++str)
		if (*str < '0' || *str > '9')
			return (print_error(WRONG_NB1, WRONG_NB2, FALSE));
	config->nb_philo = ft_atoi_strict(argv[1]);
	if (config->nb_philo < 1 || config->nb_philo > INT_MAX)
		return (print_error(WRONG_NB1, WRONG_NB2, FALSE));
	if (!record_times(argv, config))
		return (print_error(WRONG_TIME1, WRONG_TIME2, FALSE));
	config->min_nb_meal = -1;
	if (argc == 6)
	{
		str = argv[5] + (*argv[5] == '+') - 1;
		while (*++str)
			if (*str < '0' || *str > '9')
				return (print_error(WRONG_MEAL1, WRONG_MEAL2, FALSE));
		config->min_nb_meal = ft_atoi_strict(argv[5]);
		if (config->min_nb_meal < 0 || config->min_nb_meal > INT_MAX)
			return (print_error(WRONG_MEAL1, WRONG_MEAL2, FALSE));
	}
	return (TRUE);
}
