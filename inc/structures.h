#ifndef STURCTURES_H
# define STURCTURES_H

# include <pthread.h>
# include "boolean.h"

typedef struct s_mutexes
{
	pthread_mutex_t	is_speaking;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*is_eating;
}				t_mutexes;

typedef struct s_diner
{
	t_mutexes	mutexes;
	pthread_t	*philo_threads;
	pthread_t	*philo_monitors;
	t_bool		is_diner_over;
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
	pthread_mutex_t	*is_speaking;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*is_eating;
	int				nb_forks;
	int				fork_left;
	int				fork_right;
	t_bool			*is_diner_over;
}				t_philo;

#endif
