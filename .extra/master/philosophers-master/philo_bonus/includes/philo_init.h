/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/13 11:56:17 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INIT_H
# define PHILO_INIT_H

# include <semaphore.h>
# include "boolean.h"
# include "philo_parsing.h"
# include "philosophers.h"

# define FORKS				"forks"
# define IS_SPEAKING		"is_speaking"
# define REACHED_NB_MEAL	"reached_nb_meal"
# define DINER_OVER			"diner_over"

t_bool	init_diner_setup(t_diner *diner_setup, int nb_philo, int min_nb_meal);
t_bool	init_semaphores(t_semaphores *semaphores, int nb_philo);
char	*ft_itoa(int n);
char	*ft_strjoin_del(char *s1, char *s2, int to_del);
t_bool	init_philosophers(t_philo **philosophers, int nb_philo,
			t_semaphores *semaphores, t_config *config);

#endif
