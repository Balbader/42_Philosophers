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

# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// utils
int				ft_atoi(const char *nptr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_is_num(char *arg);
char			*ft_itoa(int n);
void			*ft_calloc(size_t nmemb, size_t size);

// parsing
int				ft_check_args(int ac, char **av);
int				ft_check_av(char *arg);

// SIM INITIALISATION
int				init_sim(t_rules *rules, char **av);

// SIM UTILS
unsigned long	get_time(void);
void			print_action(t_philo *p, t_rules *r, char *s);
void			isleep(unsigned long ms);
unsigned long	time_diff(unsigned long a, unsigned long b);
int				check_health(t_rules *r);
void			print_action(t_philo *p, t_rules *r, char *s);
void			handle_eat(t_rules *r, t_philo *p);

// SIM
int				launch_sim(t_rules *rules);

// destroy
int				ft_destroy_mutexes(t_rules *r);

#endif
