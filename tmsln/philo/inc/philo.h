/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:49:41 by tmalless          #+#    #+#             */
/*   Updated: 2023/03/28 16:47:02 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <sys/time.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				left_fork_idx;
	int				right_fork_idx;
	unsigned long	last_meal;
	int				nb_meal;
	int				hunger;
	pthread_t		thread;
	struct s_philo	*left_philo;
	struct s_rules	*rules;
}	t_philo;

typedef struct s_rules
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				x_meal;
	int				dead_end;
	int				all_ate;
	unsigned long	start;
	pthread_t		thread;
	struct s_philo	philos[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	printing;
	pthread_mutex_t	health_check;
}	t_rules;

// UTILS
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);

// ARGS CHECKING
int				check_args(int ac, char **av);

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

// CLEAN
int				clean_mem(t_rules *r);

#endif