/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:59:08 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 16:05:47 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

# define E_OK 0
# define E_MALLOC 1
# define FORK 2
# define NO_FORK 3
# define ERROR 4
# define DEATH 5

# define BLUE "\033[0;36m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define PURPLE "\033[0;35m"

# define END_COLOR "\033[0;0m"

typedef struct s_args
{
	int					i;
	int					ac;
	int					nb_philo;
	int					die;
	int					eat;

	int					sleep;
	struct timeval		current_time;
	long long			timestamp;
	long long			timestamp_seconds;
	pthread_mutex_t		time_mutex;
	pthread_mutex_t		print_mutex;
	int					*death;
	int					*meals;
	int					*forks;
	pthread_t			*threads;
	pthread_mutex_t		*forks_mutex;
	pthread_mutex_t		*death_mutex;

}				t_args;

typedef struct s_philo {
	char			string[100];
	int				number;
	t_args			*data;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

int			init(t_args *data, char **av, int ac, t_philo **philo);
void		*thread(void *arg);
int			is_dead(t_philo *philo);
int			eat(t_philo **philo);
int			eat_odd(t_philo **philo);
int			eat_even(t_philo **philo);
int			mysleep(t_philo *philo);
void		ft_putstr_fd(char *s, int fd);
long long	getime(t_args *data);
int			mutex_init(t_philo **philo, t_args *data);
void		free_all(t_args *data, t_philo **philo);

// printf et libft functions 

int			ft_atoi(const char *str);
int			ft_printf(const char *input, ...);
int			check_charset(const char *to_check);
void		ft_putchar(int c);
int			ft_put_lowcase_hexnbr(long long n);
int			ft_put_upcase_hexnbr(long long n);
size_t		ft_strlen(const char *s);
int			ft_putnbr_nreturn_lenght(int n);
int			ft_putnbr_unsigned_int_nreturn_lenght(unsigned int n);
int			ft_putstr_nreturn_lenght(char *s);
int			check_percent_error(const char *input);
int			conversions(int i, va_list args, const char *input);
int			ft_putaddress(unsigned long long n);
int			conversions_bis(int i, va_list args, const char *input);
void		ft_putstr(char *s);
int			ft_isdigit(int c);

#endif
