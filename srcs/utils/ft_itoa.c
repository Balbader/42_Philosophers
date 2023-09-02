/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:33:26 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:33:27 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

static char	*ft_if_neg(long int num, int cpt)
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

static char	*ft_manage_pos(long int num, int cpt)
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
		return (ft_if_neg(num * -1, cpt));
	else
		return (ft_manage_pos(num, cpt));
}
