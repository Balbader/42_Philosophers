/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/13 11:56:17 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "philo_utils.h"
#include "philo_parsing.h"
#include "philosophers.h"
#include "philo_init.h"
#include "philo_diner.h"

#define ERROR		-1

#define SEM_CLOSE	"A semaphore couldn't be closed"
#define SEM_UNLINK	"A semaphore couldn't be unlinked"

static void	destroy_semaphore(sem_t *semaphore, char *sem_name)
{
	if (sem_close(semaphore) != 0)
		print_error(SEM_CLOSE, NULL, ERROR);
	if (sem_unlink(sem_name) != 0)
		print_error(SEM_UNLINK, NULL, ERROR);
}

static void	clean_semaphores(t_semaphores *semaphores, int nb_philo)
{
	int		i;

	if (semaphores->forks != SEM_FAILED)
		destroy_semaphore(semaphores->forks, FORKS);
	if (semaphores->is_speaking != SEM_FAILED)
		destroy_semaphore(semaphores->is_speaking, IS_SPEAKING);
	if (semaphores->reached_nb_meal != SEM_FAILED)
		destroy_semaphore(semaphores->reached_nb_meal, REACHED_NB_MEAL);
	if (semaphores->diner_over != SEM_FAILED)
		destroy_semaphore(semaphores->diner_over, DINER_OVER);
	i = 0;
	while (i < nb_philo && semaphores->is_eating
		&& semaphores->is_eating[i] != SEM_FAILED)
	{
		if (sem_close(semaphores->is_eating[i]) != 0)
			print_error(SEM_CLOSE, NULL, ERROR);
		if (sem_unlink(semaphores->names[i]) != 0)
			print_error(SEM_UNLINK, NULL, ERROR);
		free(semaphores->names[i++]);
	}
	if (semaphores->is_eating)
		free(semaphores->is_eating);
	if (semaphores->names)
		free(semaphores->names);
}

static int	clean_exit(t_diner *diner_setup, t_philo *philosophers,
				int nb_philo, int return_value)
{
	int		i;
	int		status;

	i = 0;
	while (i < nb_philo)
	{
		if (diner_setup->philo_pids[i] >= 0)
		{
			waitpid(diner_setup->philo_pids[i], &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				return_value = ERROR;
		}
		i++;
	}
	free(diner_setup->philo_pids);
	clean_semaphores(&diner_setup->semaphores, nb_philo);
	if (philosophers)
		free(philosophers);
	return (return_value);
}

int	main(int argc, char *argv[])
{
	t_config		config;
	int				nb_philo;
	t_diner			diner_setup;
	t_semaphores	*semaphores;
	t_philo			*philosophers;

	if (!parse_config(argc, argv, &config))
		return (ERROR);
	nb_philo = config.nb_philo;
	semaphores = &diner_setup.semaphores;
	if (!init_diner_setup(&diner_setup, nb_philo, config.min_nb_meal))
		return (ERROR);
	if (!init_semaphores(semaphores, nb_philo))
		return (clean_exit(&diner_setup, NULL, nb_philo, ERROR));
	if (!init_philosophers(&philosophers, nb_philo, semaphores, &config))
		return (clean_exit(&diner_setup, NULL, nb_philo, ERROR));
	if (!launch_diner(&diner_setup, philosophers, nb_philo))
		return (clean_exit(&diner_setup, philosophers, nb_philo, ERROR));
	if (!monitor_diner(&diner_setup, semaphores))
		return (clean_exit(&diner_setup, philosophers, nb_philo, ERROR));
	return (clean_exit(&diner_setup, philosophers, nb_philo, 0));
}
