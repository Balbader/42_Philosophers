/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/13 11:56:17 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philo_parsing.h"
#include "philosophers.h"
#include "philo_init.h"

#define IS_EATING		"is_eating"

#define SEM_OPEN		"A semaphore couldn't be opened"
#define SEM_ALLOC		"A semaphore array couldn't be allocated"
#define SEM_NAME_ALLOC	"A semaphore's name couldn't be allocated"
#define PHILO_PID_ALLOC	"The philosophers' pid array couldn't be allocated"
#define INIT_PID		-2
#define PHILO_ALLOC		"The philosophers' array couldn't be allocated"

static void	unlink_and_open_semaphores(t_semaphores *semaphores, int nb_philo)
{
	sem_unlink(FORKS);
	sem_unlink(IS_SPEAKING);
	sem_unlink(REACHED_NB_MEAL);
	sem_unlink(DINER_OVER);
	semaphores->forks = sem_open(FORKS,
			O_RDWR | O_CREAT | O_TRUNC, 00664, nb_philo);
	semaphores->is_speaking = sem_open(IS_SPEAKING,
			O_RDWR | O_CREAT | O_TRUNC, 00664, 1);
	semaphores->reached_nb_meal = sem_open(REACHED_NB_MEAL,
			O_RDWR | O_CREAT | O_TRUNC, 00664, 0);
	semaphores->diner_over = sem_open(DINER_OVER,
			O_RDWR | O_CREAT | O_TRUNC, 00664, 0);
}

static t_bool	init_array_semaphores(t_semaphores *semaphores, int nb_philo)
{
	int		i;
	char	*sem_name;

	i = 0;
	while (i < nb_philo)
	{
		semaphores->is_eating[i] = SEM_FAILED;
		sem_name = ft_itoa(i + 1);
		if (!sem_name)
			return (print_error(SEM_NAME_ALLOC, NULL, FALSE));
		sem_name = ft_strjoin_del(IS_EATING, sem_name, 2);
		if (!sem_name)
			return (print_error(SEM_NAME_ALLOC, NULL, FALSE));
		sem_unlink(sem_name);
		semaphores->is_eating[i] = sem_open(sem_name,
				O_RDWR | O_CREAT | O_TRUNC, 00664, 1);
		if (semaphores->is_eating[i] == SEM_FAILED)
		{
			free(sem_name);
			return (print_error(SEM_OPEN, NULL, FALSE));
		}
		semaphores->names[i] = sem_name;
		i++;
	}
	return (TRUE);
}

t_bool	init_semaphores(t_semaphores *semaphores, int nb_philo)
{
	unlink_and_open_semaphores(semaphores, nb_philo);
	semaphores->is_eating = NULL;
	semaphores->names = NULL;
	if (semaphores->forks == SEM_FAILED || semaphores->diner_over == SEM_FAILED
		|| semaphores->is_speaking == SEM_FAILED
		|| semaphores->reached_nb_meal == SEM_FAILED)
		return (print_error(SEM_OPEN, NULL, FALSE));
	semaphores->is_eating = (sem_t **)malloc(nb_philo * sizeof(sem_t *));
	if (semaphores->is_eating)
		semaphores->names = (char **)malloc(nb_philo * sizeof(char *));
	if (!semaphores->is_eating || !semaphores->names)
	{
		if (semaphores->is_eating)
		{
			free(semaphores->is_eating);
			semaphores->is_eating = NULL;
		}
		return (print_error(SEM_ALLOC, NULL, FALSE));
	}
	return (init_array_semaphores(semaphores, nb_philo));
}

t_bool	init_diner_setup(t_diner *diner_setup, int nb_philo, int min_nb_meal)
{
	int		i;

	diner_setup->philo_pids = (pid_t *)malloc(nb_philo * sizeof(pid_t));
	if (!diner_setup->philo_pids)
		return (print_error(PHILO_PID_ALLOC, NULL, FALSE));
	i = 0;
	while (i < nb_philo)
		diner_setup->philo_pids[i++] = INIT_PID;
	diner_setup->nb_philo = nb_philo;
	diner_setup->min_nb_meal = min_nb_meal;
	diner_setup->is_diner_over = FALSE;
	return (TRUE);
}

t_bool	init_philosophers(t_philo **philosophers, int nb_philo,
							t_semaphores *semaphores, t_config *config)
{
	int			i;
	t_philo		*philo;

	*philosophers = (t_philo *)malloc(nb_philo * sizeof(t_philo));
	if (!*philosophers)
		return (print_error(PHILO_ALLOC, NULL, FALSE));
	i = -1;
	while (++i < nb_philo)
	{
		philo = &(*philosophers)[i];
		philo->id = i + 1;
		philo->nb_meal = 0;
		philo->min_nb_meal = config->min_nb_meal;
		philo->time_to_die = config->time_to_die;
		philo->time_to_eat = config->time_to_eat;
		philo->time_to_sleep = config->time_to_sleep;
		philo->nb_forks = config->nb_philo;
		philo->forks = semaphores->forks;
		philo->is_speaking = semaphores->is_speaking;
		philo->is_eating = semaphores->is_eating[i];
		philo->reached_nb_meal = semaphores->reached_nb_meal;
		philo->diner_over = semaphores->diner_over;
		philo->is_diner_over = FALSE;
	}
	return (TRUE);
}
