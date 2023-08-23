#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# include "philosophers.h"

int			print_error(char *error_msg1, char *error_msg2, int return_value);
time_t		get_time(void);
void		ft_memdel(void **ptr);
void		ft_usleep(time_t usec);

#endif
