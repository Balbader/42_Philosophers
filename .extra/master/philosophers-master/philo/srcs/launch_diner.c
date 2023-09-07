/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_diner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:38:18 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:43:01 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philosophers.h"
#include "philo_diner.h"

#define THREAD_ALLOC	"The threads couldn't be allocated"
#define THREAD_CREATE	"A thread couldn't be created"

static t_bool	create_monitor_threads(pthread_t *philo_threads,
						pthread_t *philo_monitors, t_philo *philosophers, int i)
{
	if (pthread_create(&philo_monitors[i], NULL,
			&monitor_philo, &philosophers[i]) != 0)
	{
		*philosophers[0].is_diner_over = TRUE;
		pthread_join(philo_threads[i], NULL);
		while (--i >= 0)
		{
			pthread_join(philo_threads[i], NULL);
			pthread_join(philo_monitors[i], NULL);
		}
		ft_memdel((void **)&philo_threads);
		ft_memdel((void **)&philo_monitors);
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	create_threads(pthread_t *philo_threads,
						pthread_t *philo_monitors, t_philo *philosophers, int i)
{
	if (pthread_create(&philo_threads[i], NULL, &diner, &philosophers[i]) != 0)
	{
		*philosophers[0].is_diner_over = TRUE;
		while (--i >= 0)
		{
			pthread_join(philo_threads[i], NULL);
			pthread_join(philo_monitors[i], NULL);
		}
		ft_memdel((void **)&philo_threads);
		ft_memdel((void **)&philo_monitors);
		return (FALSE);
	}
	if (!create_monitor_threads(philo_threads, philo_monitors, philosophers, i))
		return (FALSE);
	return (TRUE);
}

static t_bool	launch_threads(t_diner *diner_setup,
								t_philo *philosophers, int nb_philo)
{
	int			i;
	time_t		time;

	i = 0;
	time = get_time();
	while (i < nb_philo)
	{
		philosophers[i].last_meal = time;
		philosophers[i].start_time = time;
		if (!create_threads(diner_setup->philo_threads,
				diner_setup->philo_monitors, philosophers, i))
			return (print_error(THREAD_CREATE, NULL, FALSE));
		i += 2;
		if (i % 2 == 0 && i >= nb_philo)
		{
			i = 1;
			ft_usleep(2000);
		}
	}
	return (TRUE);
}

t_bool	launch_diner(t_diner *diner_setup, t_philo *philosophers, int nb_philo)
{
	diner_setup->philo_threads = malloc(nb_philo * sizeof(pthread_t));
	diner_setup->philo_monitors = malloc(nb_philo * sizeof(pthread_t));
	if (!diner_setup->philo_threads || !diner_setup->philo_monitors)
	{
		if (diner_setup->philo_threads)
			ft_memdel((void **)&diner_setup->philo_threads);
		if (diner_setup->philo_monitors)
			ft_memdel((void **)&diner_setup->philo_monitors);
		return (print_error(THREAD_ALLOC, NULL, FALSE));
	}
	return (launch_threads(diner_setup, philosophers, nb_philo));
}
