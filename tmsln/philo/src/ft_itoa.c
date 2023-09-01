/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:02:26 by tmalless          #+#    #+#             */
/*   Updated: 2023/03/30 15:33:48 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static char	*handleneg(long int num, int cpt)
{
	char	*r;

	r = (char *) ft_calloc(cpt + 2, sizeof(char));
	if (!r)
		return (0);
	while (num != 0)
	{
		r[cpt] = num % 10 + '0';
		num = num / 10;
		cpt--;
	}
	r[0] = '-';
	return (r);
}

static char	*handlepos(long int num, int cpt)
{
	char	*r;

	r = (char *) ft_calloc(cpt + 1, sizeof(char));
	if (!r)
		return (0);
	while (num != 0)
	{
		r[cpt - 1] = num % 10 + '0';
		num = num / 10;
		cpt--;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	char			*r;
	int				cpt;
	long int		num;

	num = n;
	cpt = 0;
	while (n != 0)
	{
		n /= 10;
		cpt++;
	}
	if (num == 0)
	{
		r = (char *) ft_calloc(2, sizeof(char));
		r[0] = '0';
		return (r);
	}
	if (num < 0)
		return (handleneg(num * -1, cpt));
	else
		return (handlepos(num, cpt));
}
