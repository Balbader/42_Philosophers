/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:50:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/03/27 13:26:15 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	s;
	unsigned long	u;

	gettimeofday(&time, NULL);
	s = time.tv_sec;
	u = time.tv_usec;
	return (s * 1000 + u / 1000);
}

unsigned long	time_diff(unsigned long a, unsigned long b)
{
	return (a - b);
}

void	isleep(unsigned long ms)
{
	unsigned long	t;

	t = get_time();
	while (time_diff(get_time(), t) < ms)
		usleep(50);
}

int	main(int ac, char **av)
{
	t_rules			*rules;

	rules = malloc(sizeof(t_rules) * 1);
	if (!rules)
		return (write(2, "Error:\nMalloc issue\n", 21));
	if (check_args(ac, av))
	{
		free(rules);
		return (0);
	}
	if (init_sim(rules, av) > 1)
	{
		free(rules);
		return (0);
	}
	else if (init_sim(rules, av) == 1)
		return (clean_mem(rules));
	if (launch_sim(rules))
		return (clean_mem(rules));
	return (1);
}
