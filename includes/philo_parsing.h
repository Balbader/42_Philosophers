#ifndef PHILO_PARSING_H
# define PHILO_PARSING_H

# include "boolean.h"

typedef struct s_config
{
	long	nb_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	min_nb_meal;
}				t_config;

t_bool	parse_config(int argc, char *argv[], t_config *config);

#endif
