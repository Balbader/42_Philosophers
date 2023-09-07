/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_diner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:38:18 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:35:36 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DINER_H
# define PHILO_DINER_H

# include "boolean.h"
# include "philosophers.h"

# define FORK			"has taken a fork"
# define EAT			"is eating"
# define SLEEP			"is sleeping"
# define THINK			"is thinking"
# define DIE			"died"
# define MIN_NB_MEAL	"Each philosopher has eaten at least"

t_bool	launch_diner(t_diner *diner_setup, t_philo *philosophers, int nb_philo);
void	*diner(void *arg);
void	*monitor_philo(void *arg);
void	monitor_nb_meals(t_philo *philosophers, int nb_philo, int min_nb_meal);
t_bool	speak(t_philo *philo, time_t time, char *msg);
t_bool	announce_death(t_philo *philo, time_t time, char *msg);

#endif
