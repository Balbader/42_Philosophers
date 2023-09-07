/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:50:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/03/30 15:31:24 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*solo_philo(t_rules *r, t_philo *p)
{
	pthread_mutex_lock(&(r->forks[p->right_fork_idx]));
	print_action(p, r, "has taken a fork");
	pthread_mutex_unlock(&(r->forks[p->right_fork_idx]));
	return (0);
}

void	*threader(void *void_philo)
{
	t_philo	*p;
	t_rules	*r;

	p = (t_philo *)void_philo;
	r = p->rules;
	if (r->nb_philo == 1)
		return (solo_philo(r, p));
	if (p->id % 2 == 0)
		isleep(r->time_to_eat);
	while (1)
	{
		if (check_health(r) == 0)
			break ;
		pthread_mutex_lock(&(r->forks[p->right_fork_idx]));
		print_action(p, r, "has taken a fork");
		pthread_mutex_lock(&(r->forks[p->left_fork_idx]));
		print_action(p, r, "has taken a fork");
		handle_eat(r, p);
		pthread_mutex_unlock(&(r->forks[p->right_fork_idx]));
		pthread_mutex_unlock(&(r->forks[p->left_fork_idx]));
		print_action(p, r, "is sleeping");
		isleep(r->time_to_sleep);
		print_action(p, r, "is thinking");
	}
	return (0);
}

int	check_vitals(t_rules *r, int i)
{
	pthread_mutex_lock(&(r->health_check));
	if (time_diff(get_time(), r->philos[i].last_meal)
		> (unsigned long)r->time_to_die)
	{
		r->dead_end = 1;
		pthread_mutex_unlock(&(r->health_check));
		print_action(&(r->philos[i]), r, "died");
		return (1);
	}
	else if (r->x_meal > 0 && r->philos[i].hunger == 1)
	{
		if (r->philos[i].nb_meal >= r->x_meal)
		{
			r->philos[i].hunger = 0;
			pthread_mutex_unlock(&(r->health_check));
			return (2);
		}
		pthread_mutex_unlock(&(r->health_check));
	}
	else
		pthread_mutex_unlock(&(r->health_check));
	return (0);
}

void	t_end(t_rules *r, int i, int ans)
{
	int	full_philos;

	full_philos = 0;
	while (1)
	{
		i = 0;
		if (check_health(r) == 0)
			break ;
		while (i < r->nb_philo)
		{
			ans = check_vitals(r, i);
			if (ans == 1)
				break ;
			else if (ans == 2)
				full_philos++;
			if (full_philos == r->nb_philo)
			{
				pthread_mutex_lock(&(r->health_check));
				r->all_ate = 1;
				pthread_mutex_unlock(&(r->health_check));
			}
			i++;
		}
	}
	usleep(200);
}

int	launch_sim(t_rules *rules)
{
	int				i;

	i = 0;
	rules->start = get_time();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(rules->philos[i].thread), NULL,
				threader, &(rules->philos[i])))
			return (write(2, "Error:\nIssue creating threads.\n", 31));
		pthread_mutex_lock(&(rules->health_check));
		rules->philos[i].last_meal = get_time();
		pthread_mutex_unlock(&(rules->health_check));
		i++;
	}
	t_end(rules, 0, 0);
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(rules->philos[i].thread, NULL);
		i++;
	}
	clean_mem(rules);
	return (0);
}
