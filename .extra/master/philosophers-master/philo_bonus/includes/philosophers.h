/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:42:15 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <semaphore.h>
# include "boolean.h"

typedef struct s_semaphores
{
	sem_t			*forks;
	sem_t			*is_speaking;
	sem_t			**is_eating;
	char			**names;
	sem_t			*reached_nb_meal;
	sem_t			*diner_over;
}				t_semaphores;

typedef struct s_diner
{
	t_semaphores	semaphores;
	pid_t			*philo_pids;
	int				nb_philo;
	int				min_nb_meal;
	t_bool			is_diner_over;
}				t_diner;

typedef struct s_philo
{
	int				id;
	int				nb_meal;
	int				min_nb_meal;
	time_t			last_meal;
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				nb_forks;
	sem_t			*forks;
	sem_t			*is_speaking;
	sem_t			*is_eating;
	sem_t			*reached_nb_meal;
	sem_t			*diner_over;
	t_bool			is_diner_over;
}				t_philo;

#endif
