/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_philosophers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:10:27 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 16:10:30 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	ft_setup_philosophers(t_philo *philo, int i, t_dinner *dinner_setup,
		t_config *config)
{
	t_mutexes	*mutexes;
	int			nb_philo;

	mutexes = &dinner_setup->mutexes;
	nb_philo = config->nb_philo;
	philo->id = i + 1;
	philo->nb_meal = 0;
	philo->min_nb_meal = config->min_nb_meal;
	philo->time_to_die = config->time_to_die;
	philo->time_to_eat = config->time_to_eat;
	philo->time_to_sleep = config->time_to_sleep;
	philo->is_thinking = &mutexes->is_thinking;
	philo->forks = mutexes->forks;
	philo->is_eating = &mutexes->is_eating[i];
	philo->nb_forks = config->nb_philo;
	philo->fork_left = i;
	philo->fork_right = (i + 1) % nb_philo;
	philo->is_dinner_over = &dinner_setup->is_dinner_over;
}
