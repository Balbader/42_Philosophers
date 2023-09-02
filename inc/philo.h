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
int				ft_destroy_mutexes(t_rules *r);

// check_dinner
int				ft_check_vitals(t_rules *r, int i);
int				ft_check_health(t_rules *r);

// start dinner
int				ft_start_dinner(t_rules *rules);

// dinner
void			ft_is_eating(t_rules *r, t_philo *p);
void			ft_print_state(t_philo *p, t_rules *r, char *action);
void			*ft_threader(void *void_philo);
void			*ft_philo_alone(t_rules *r, t_philo *p);
void			ft_end(t_rules *r, int i, int state);

// parsing
int				ft_check_args(int ac, char **av);
int				ft_check_av(char *arg);

// init
int				ft_init_dinner(t_rules *rules, char **av);
int				ft_init_mutex(t_rules *rules);
int				ft_init_philosophers(t_rules *rules);

// SIM UTILS
void			print_action(t_philo *p, t_rules *r, char *s);
int				check_health(t_rules *r);
void			print_action(t_philo *p, t_rules *r, char *s);
void			handle_eat(t_rules *r, t_philo *p);

// SIM
int				launch_sim(t_rules *rules);

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
