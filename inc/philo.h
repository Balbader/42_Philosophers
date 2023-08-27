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
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

//  Main
int		main(int ac, char **av);

// Parsing
t_bool	ft_parse_config(int ac, char **av, t_config *config);
t_bool	ft_record_times(char **av, t_config *config);

// Init
t_bool	ft_init_mutexes_arr(pthread_mutex_t *forks, pthread_mutex_t *is_eating,
		int nb_philo);
t_bool	ft_init_mutexes(t_mutexes *mutexes, int nb_philo);
t_bool	ft_init_philosophers(t_philo **philosophers, int nb_philo,
		t_diner *diner_setup, t_config *config);
void	ft_setup_philosophers(t_philo *philo, int i, t_diner *diner_setup,
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

// Check Dinner
void	ft_check_meal_count(t_philo *philosophers, int nb_philo,
		int min_nb_meal);
void	*ft_check_philosopher(void *arg);

// Think
t_bool	ft_is_thinking(t_philo *philo, time_t time, char *message);

// Utils
int		ft_strcmp(const char *s1, const char *s2);
int		ft_print_err(char *err_msg_1, char *err_msg_2, int ret_val);
int		ft_clean_exit(t_diner *diner_setup, t_philo *philosophers,
			int nb_philo, int ret_val);
long	ft_atoi_long(const char *str);
void	ft_clean_mutexes(t_mutexes *mutexes, int nb_philo);
void	ft_putstr_fd(char *s, int fd);
void	ft_memdel(void **ptr);
void	ft_usleep(time_t usec);
time_t	ft_get_time(void);
t_bool	ft_is_dead(t_philo *philo, time_t time, char *message);

#endif // !PHILO_H
