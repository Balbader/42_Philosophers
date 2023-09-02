/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:24:00 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:24:02 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structures.h"
# include "define.h"

# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// destroy
int				ft_destroy_mutexes(t_config *conf);

// check_dinner
int				ft_check_vitals(t_config *philo, int i);
int				ft_check_health(t_config *philos);

// start dinner
int				ft_start_dinner(t_config *conf);

// dinner
void			ft_is_eating(t_config *conf, t_philo *philo);
void			ft_print_state(t_philo *philo, t_config *conf, char *action);
void			*ft_threader(void *void_philo);
void			*ft_philo_alone(t_config *conf, t_philo *philo);
void			ft_end(t_config *philosophers, int i, int state);

// parsing
int				ft_check_args(int ac, char **av);
int				ft_check_av(char *arg);

// init
int				ft_init_dinner(t_config *conf, char **av);
int				ft_init_mutex(t_config *conf);
int				ft_init_philosophers(t_config *conf);

// time
void			ft_usleep(unsigned long ms);
unsigned long	ft_get_time(void);
unsigned long	ft_time_diff(unsigned long a, unsigned long b);

// utils
int				ft_atoi(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_is_num(char *arg);
char			*ft_itoa(int n);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_putstr_fd(char *s, int fd);

#endif
