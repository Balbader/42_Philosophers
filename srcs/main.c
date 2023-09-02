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

int	main(int ac, char **av)
{
	t_rules			*rules;

	rules = malloc(sizeof(t_rules) * 1);
	if (!rules)
		return (write(2, "Error:\nMalloc issue\n", 21));
	if (ft_check_args(ac, av))
	{
		free(rules);
		return (0);
	}
	if (ft_init_dinner(rules, av) > 1)
	{
		free(rules);
		return (0);
	}
	else if (ft_init_dinner(rules, av) == 1)
		return (ft_destroy_mutexes(rules));
	if (ft_start_dinner(rules))
		return (ft_destroy_mutexes(rules));
	return (1);
}
