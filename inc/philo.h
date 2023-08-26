/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:19:08 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 09:19:10 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "structures.h"
#include "define.h"

// Parsing
t_bool	parse_config(int argc, char *argv[], t_config *config);

// Init
t_bool	init_mutexes(t_mutexes *mutexes, int nb_philo);
void	init_diner_setup(t_diner *diner_setup);
t_bool	init_philosophers(t_philo **philosophers, int nb_philo,
			t_diner *diner_setup, t_config *config);

// Start Dinner
t_bool	ft_init_threads_monitoring(pthread_t *philo_threads,
			pthread_t *philo_monitor, t_philo *philosophers, int i);

t_bool	launch_diner(t_diner *diner_setup, t_philo *philosophers, int nb_philo);
void	*monitor_philo(void *arg);
void	monitor_nb_meals(t_philo *philosophers, int nb_philo, int min_nb_meal);
t_bool	speak(t_philo *philo, time_t time, char *msg);
t_bool	announce_death(t_philo *philo, time_t time, char *msg);

// Dinner
t_bool	ft_eat(t_philo *philo);
void	*ft_diner(void *arg);

// Utils
int		print_error(char *error_msg1, char *error_msg2, int return_value);
time_t	get_time(void);
void	ft_memdel(void **ptr);
void	ft_usleep(time_t usec);

#endif // !PHILO_H
