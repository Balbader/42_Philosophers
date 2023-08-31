/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_times.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:13:20 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 17:13:30 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

t_bool	ft_parse_times(char **av, t_config *config)
{
	static int	i = 2;
	char		*str;
	long		time;	

	str = av[i] + (*av[i] == '+');
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (FALSE);
		str++;
	}
	time = ft_atoi_long(av[i]);
	if (time > INT_MAX)
		return (FALSE);
	if (i == 2)
		config->time_to_die = time;
	else if (i == 3)
		config->time_to_eat = time;
	else
		config->time_to_sleep = time;
	if (i++ < 4)
		return (ft_parse_times(av, config));
	return (TRUE);
}
