/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:37:25 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 10:12:44 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	getime(t_args *time)
{
	long long		x;
	struct timeval	current_time;

	gettimeofday(&(current_time), NULL);
	x = (((current_time.tv_sec - time->timestamp_seconds) * 1000000) + \
	(current_time.tv_usec - time->timestamp)) / 1000;
	return (x);
}
