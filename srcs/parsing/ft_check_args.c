/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:46:21 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:46:23 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		ft_putstr_fd(ARG_NB_ERR, 2);
	while (i < ac)
	{
		if (!ft_is_num(av[i]))
			ft_putstr_fd(ARG_ERR, 2);
		if (!ft_check_av(av[i]))
			ft_putstr_fd(ARG_LIMIT_ERR, 2);
		i++;
	}
	return (0);
}
