/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:38:18 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/15 12:43:03 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include "philosophers.h"

static void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (i > 0)
		write(fd, s, i);
}

int	print_error(char *error_msg1, char *error_msg2, int return_value)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_msg1, 2);
	if (error_msg2)
		ft_putstr_fd(error_msg2, 2);
	ft_putstr_fd("\n", 2);
	return (return_value);
}

time_t	get_time(void)
{
	time_t			milliseconds;
	struct timeval	time;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000;
	milliseconds += time.tv_usec / 1000;
	return (milliseconds);
}

void	ft_memdel(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	ft_usleep(time_t usec)
{
	time_t		start_time;
	time_t		elapsed_time;
	time_t		milliseconds;

	start_time = get_time();
	elapsed_time = get_time() - start_time;
	milliseconds = usec / 1000;
	while (elapsed_time < milliseconds)
	{
		usleep((milliseconds - elapsed_time) / 2);
		elapsed_time = get_time() - start_time;
	}
}
