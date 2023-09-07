/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:50:34 by tmalless          #+#    #+#             */
/*   Updated: 2023/03/24 16:16:38 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_is_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ov_check(char *arg)
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

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (write(2, "Error:\nWrong number of arguments.\n", 34));
	while (i < ac)
	{
		if (!ft_is_num(av[i]))
			return (write(2, "Error:\nCan't interpret some characters.\n", 40));
		if (!ov_check(av[i]))
			return (write(2, "Error:\nOut of range values.\n", 28));
		i++;
	}
	return (0);
}
