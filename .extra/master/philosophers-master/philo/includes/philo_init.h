/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:38:18 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/08 16:36:47 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INIT_H
# define PHILO_INIT_H

# include "boolean.h"
# include "philo_parsing.h"
# include "philosophers.h"

t_bool	init_mutexes(t_mutexes *mutexes, int nb_philo);
void	init_diner_setup(t_diner *diner_setup);
t_bool	init_philosophers(t_philo **philosophers, int nb_philo,
			t_diner *diner_setup, t_config *config);

#endif
