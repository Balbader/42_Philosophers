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

# include "structures.h"
# include "define.h"

# include <stdio.h>

// Parsing

// Init
t_bool	ft_init_mutexes_arr(pthread_mutex_t *forks, pthread_mutex_t *is_eating,
		int nb_philo);
t_bool	ft_init_mutexes(t_mutexes *mutexes, int nb_philo);
t_bool	ft_init_philosophers(t_philo **philosophers, int nb_philo,
		t_diner *diner_setup, t_config *config);
void	ft_setup_philosophers(t_philo *philo, int i, t_diner_setup,
		t_config *config);

// Start Dinner
t_bool	ft_init_threads_monitoring(pthread_t *philo_threads,
			pthread_t *philo_monitor, t_philo *philosophers, int i);
t_bool	ft_init_threads(pthread_t *philo_threads, pthread_t *philo_monitors,
		t_philo *philosophers, int i);
t_bool	ft_start_threads(t_diner *diner_setup, t_philo *phlosophers,
		int nb_philo);
t_bool	ft_start_dinner(t_diner *diner_setup, t_philo *philosophers,
		int nb_philo);

// Dinner
t_bool	ft_eat(t_philo *philo);
void	ft_setup_dinner(t_diner *diner_setup);
void	*ft_diner(void *arg);

// Think
t_bool	ft_is_thinking(t_philo *philo, time_t time, char *message);

// Utils
int		ft_strcmp(const char *s1, const char *s2);
t_bool	ft_is_dead(t_philo *philo, time_t time, char *message);

// ============================================================================

// Parsing
t_bool	parse_config(int argc, char *argv[], t_config *config);

// Init
t_bool	init_mutexes(t_mutexes *mutexes, int nb_philo);
void	init_diner_setup(t_diner *diner_setup);
t_bool	init_philosophers(t_philo **philosophers, int nb_philo,
			t_diner *diner_setup, t_config *config);
t_bool	launch_diner(t_diner *diner_setup, t_philo *philosophers, int nb_philo);
void	*monitor_philo(void *arg);
void	monitor_nb_meals(t_philo *philosophers, int nb_philo, int min_nb_meal);
t_bool	speak(t_philo *philo, time_t time, char *msg);
t_bool	announce_death(t_philo *philo, time_t time, char *msg);

// Utils
int		print_error(char *error_msg1, char *error_msg2, int return_value);
time_t	get_time(void);
void	ft_memdel(void **ptr);
void	ft_usleep(time_t usec);

#endif // !PHILO_H
