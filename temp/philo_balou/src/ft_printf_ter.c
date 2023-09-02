/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:20:15 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 14:55:15 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_nreturn_lenght(int n)
{
	unsigned int	nbr;
	char			modulo;
	int				length;

	length = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		length++;
	}
	nbr = (unsigned int)n;
	if (nbr > 9)
		length += ft_putnbr_nreturn_lenght(nbr / 10);
	modulo = nbr % 10 + 48;
	write(1, &modulo, 1);
	length++;
	return (length);
}

int	ft_putnbr_unsigned_int_nreturn_lenght(unsigned int n)
{
	char		modulo;
	int			length;

	length = 0;
	if (n > 9)
		length += ft_putnbr_unsigned_int_nreturn_lenght(n / 10);
	modulo = n % 10 + 48;
	write(1, &modulo, 1);
	length++;
	return (length);
}

int	ft_putstr_nreturn_lenght(char *s)
{
	int	i;

	i = 6;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (i);
	}
	else
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}

int	check_percent_error(const char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == 37 && check_charset(input + i + 1) == 0)
			return (0);
		if (input[i] == 37 && check_charset(input + i + 1) == 1)
			i += 2;
		else
			i++;
	}
	return (1);
}
