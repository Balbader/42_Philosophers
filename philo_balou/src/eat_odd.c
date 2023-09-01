/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_odd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:50:41 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 14:38:01 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	first_fork(t_philo **philo)
{
	pthread_mutex_lock((*philo)->right_fork);
	pthread_mutex_lock(&(*philo)->data->print_mutex);
	if (is_dead((*philo)) == DEATH)
	{
		pthread_mutex_unlock((*philo)->right_fork);
		pthread_mutex_unlock(&(*philo)->data->print_mutex);
		return (DEATH);
	}
	ft_printf(BLUE"%d %d has taken a fork\n", (int)getime((*philo)->data), \
	(*philo)->number);
	pthread_mutex_unlock(&(*philo)->data->print_mutex);
	if ((*philo)->data->nb_philo == 1)
		return (DEATH);
	return (E_OK);
}

static int	second_fork(t_philo **philo)
{
	pthread_mutex_lock((*philo)->left_fork);
	pthread_mutex_lock(&(*philo)->data->print_mutex);
	if (is_dead((*philo)) == DEATH)
	{
		pthread_mutex_unlock((*philo)->right_fork);
		pthread_mutex_unlock((*philo)->left_fork);
		pthread_mutex_unlock(&(*philo)->data->print_mutex);
		return (DEATH);
	}
	ft_printf(BLUE"%d %d has taken a fork\n", (int)getime((*philo)->data), \
	(*philo)->number);
	pthread_mutex_unlock(&(*philo)->data->print_mutex);
	return (E_OK);
}

static int	meal(t_philo **philo)
{
	pthread_mutex_lock(&(*philo)->data->print_mutex);
	if (is_dead((*philo)) == DEATH)
	{
		pthread_mutex_unlock((*philo)->right_fork);
		pthread_mutex_unlock((*philo)->left_fork);
		pthread_mutex_unlock(&(*philo)->data->print_mutex);
		return (DEATH);
	}
	(*philo)->last_meal = getime((*philo)->data);
	if ((*philo)->data->ac == 6)
		--(*philo)->data->meals[(*philo)->number - 1];
	ft_printf(YELLOW"%d %d is eating\n", (int)getime((*philo)->data), \
	(*philo)->number);
	pthread_mutex_unlock(&(*philo)->data->print_mutex);
	while (getime((*philo)->data) - (*philo)->last_meal < (*philo)->data->eat)
		usleep(100);
	pthread_mutex_unlock((*philo)->left_fork);
	pthread_mutex_unlock((*philo)->right_fork);
	return (E_OK);
}

int	eat_odd(t_philo **philo)
{
	if (first_fork(philo) == DEATH || second_fork(philo) == DEATH
		|| meal(philo) == DEATH)
		return (DEATH);
	return (E_OK);
}
