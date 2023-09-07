#include "../inc/philo.h"

int	check_health(t_rules *r)
{
	int	ans;

	pthread_mutex_lock(&(r->health_check));
	if (r->all_ate || r->dead_end)
		ans = 0;
	else
		ans = 1;
	pthread_mutex_unlock(&(r->health_check));
	return (ans);
}

void	print_action(t_philo *p, t_rules *r, char *s)
{
	pthread_mutex_lock(&(r->printing));
	if (check_health(r) == 0 && s[0] != 'd')
	{
		pthread_mutex_unlock(&(r->printing));
		return ;
	}
	printf("%ld %d %s\n", time_diff(get_time(), r->start), p->id, s);
	pthread_mutex_unlock(&(r->printing));
}

void	handle_eat(t_rules *r, t_philo *p)
{
	pthread_mutex_lock(&(r->health_check));
	p->last_meal = get_time();
	p->nb_meal++;
	pthread_mutex_unlock(&(r->health_check));
	print_action(p, r, "is eating");
	isleep(r->time_to_eat);
}
