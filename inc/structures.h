/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:25:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:25:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				left_fork_idx;
	int				right_fork_idx;
	unsigned long	last_meal;
	int				meal_count;
	int				hungry;
	pthread_t		thread;
	struct s_philo	*left_philo;
	struct s_config	*config;
}	t_philo;

typedef struct s_config
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				tot_meals;
	int				dead_end;
	int				all_ate;
	unsigned long	start;
	pthread_t		thread;
	struct s_philo	philos[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	printing;
	pthread_mutex_t	health_check;
}	t_config;

#endif // !STRUCTURES_H
