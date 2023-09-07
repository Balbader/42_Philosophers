/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_diner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:35:31 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DINER_H
# define PHILO_DINER_H

# include "boolean.h"
# include "philo_parsing.h"
# include "philosophers.h"

# define FORK				"has taken a fork"
# define EAT				"is eating"
# define SLEEP				"is sleeping"
# define THINK				"is thinking"
# define DIE				"died"
# define MIN_NB_MEAL		"Each philosopher has eaten at least"

# define THREAD_CREATE		"A monitor thread couldn't be created"
# define THREAD_DETACH		"A monitor thread couldn't be detached"

t_bool	launch_diner(t_diner *diner_setup, t_philo *philosophers, int nb_philo);
void	diner(t_philo *philo);
t_bool	monitor_diner(t_diner *diner_setup, t_semaphores *semaphores);
t_bool	speak(t_philo *philo, time_t time, char *msg);
t_bool	announce_death(t_philo *philo, time_t time);
void	announce_nb_meal(t_diner *diner, t_semaphores *semaphores);

#endif
