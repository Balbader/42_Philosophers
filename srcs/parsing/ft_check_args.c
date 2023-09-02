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
		return (write(2, "Error:\nWrong number of arguments.\n", 34));
	while (i < ac)
	{
		if (!ft_is_num(av[i]))
			return (write(2, "Error:\nCan't interpret some characters.\n", 40));
		if (!ft_check_av(av[i]))
			return (write(2, "Error:\nOut of range values.\n", 28));
		i++;
	}
	return (0);
}
