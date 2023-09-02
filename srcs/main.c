/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:28:47 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:28:51 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
 *
*/

int	main(int ac, char **av)
{
	t_config	*conf;

	conf = malloc(sizeof(t_config) * 1);
	if (!conf)
		return (write(2, "Error:\nMalloc issue\n", 21));
	if (ft_check_args(ac, av))
	{
		free(conf);
		return (0);
	}
	if (ft_init_dinner(conf, av) > 1)
	{
		free(conf);
		return (0);
	}
	else if (ft_init_dinner(conf, av) == 1)
		return (ft_destroy_mutexes(conf));
	if (ft_start_dinner(conf))
		return (ft_destroy_mutexes(conf));
	return (1);
}
