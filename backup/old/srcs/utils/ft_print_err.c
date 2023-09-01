/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:26:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/08/26 17:26:09 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

int	ft_print_err(char *err_msg_1, char *err_msg_2, int ret_val)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(err_msg_1, 2);
	if (err_msg_2)
		ft_putstr_fd(err_msg_2, 2);
	ft_putstr_fd("\n", 2);
	return (ret_val);
}
