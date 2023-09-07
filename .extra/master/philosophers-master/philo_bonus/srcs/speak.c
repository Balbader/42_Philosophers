/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:41:13 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdio.h>
#include "boolean.h"
#include "philo_utils.h"
#include "philosophers.h"
#include "philo_diner.h"

void	announce_nb_meal(t_diner *diner_setup, t_semaphores *semaphores)
{
	int		min_nb_meal;

	sem_post(semaphores->diner_over);
	diner_setup->is_diner_over = TRUE;
	ft_usleep(3000);
	sem_wait(semaphores->is_speaking);
	ft_usleep(3000);
	min_nb_meal = diner_setup->min_nb_meal;
	printf("%s %d %.*s\n", MIN_NB_MEAL,
		min_nb_meal, 5 - (min_nb_meal <= 1), "times");
	sem_post(semaphores->is_speaking);
}

t_bool	announce_death(t_philo *philo, time_t time)
{
	time -= philo->start_time;
	sem_wait(philo->is_speaking);
	if (!philo->is_diner_over)
	{
		sem_post(philo->diner_over);
		philo->is_diner_over = TRUE;
		ft_usleep(3000);
		printf("%10lums  %d  %s\n", time, philo->id, DIE);
		ft_usleep(3000);
	}
	sem_post(philo->is_speaking);
	return (FALSE);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}

t_bool	speak(t_philo *philo, time_t time, char *msg)
{
	if ((time - philo->last_meal) > philo->time_to_die)
		return (FALSE);
	time -= philo->start_time;
	sem_wait(philo->is_speaking);
	if (!ft_strcmp(EAT, msg) && !philo->is_diner_over)
		printf("%10lums  %d  %s\n%10lums  %d  %s\n", time, philo->id, FORK,
			time, philo->id, msg);
	else if (!philo->is_diner_over)
		printf("%10lums  %d  %s\n", time, philo->id, msg);
	sem_post(philo->is_speaking);
	return (!philo->is_diner_over);
}
