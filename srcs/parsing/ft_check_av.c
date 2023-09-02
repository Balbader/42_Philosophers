/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:46:26 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:46:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_check_av(char *arg)
{
	int		n;
	char	*tmp;

	n = ft_atoi(arg);
	tmp = ft_itoa(n);
	if (!tmp)
		return (0);
	if (ft_strcmp(arg, tmp))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
