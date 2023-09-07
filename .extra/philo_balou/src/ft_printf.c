/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:11:34 by karim             #+#    #+#             */
/*   Updated: 2023/05/01 14:54:15 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_printf(const char *input, ...)
{
	int		length;
	int		i;
	va_list	args;

	length = 0;
	va_start(args, input);
	if (input == NULL || check_percent_error(input) == 0)
		return (ft_printf("error :D printf won't compile in such a case"));
	i = 0;
	while (input[i])
	{
		while (input[i] && input[i] != '%')
		{
			ft_putchar(input[i]);
			length++;
			i++;
		}
		if (input[i] != 0)
			length += conversions(i, args, input)
				+ conversions_bis(i, args, input);
		if (input[i] != 0)
			i = i + 2;
	}
	va_end(args);
	return (length);
}

int	check_charset(const char *to_check)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "cspdiuxX%%";
	while (charset[i])
	{
		if (*(to_check) == charset[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_put_lowcase_hexnbr(long long n)
{
	unsigned long long	nbr;
	char				*hexa;
	int					i;

	i = 0;
	hexa = "0123456789abcdef";
	if (n >= 0)
		nbr = n;
	if (n < 0)
		nbr = (unsigned long long)n;
	if (nbr <= 15)
	{
		write (1, hexa + nbr, 1);
		i++;
	}
	if (nbr > 15)
	{
		i += ft_put_lowcase_hexnbr(nbr / 16);
		write (1, hexa + nbr % 16, 1);
		i++;
	}
	return (i);
}

int	ft_put_upcase_hexnbr(long long n)
{
	unsigned long long	nbr;
	char				*hexa2;
	int					y;

	y = 0;
	hexa2 = "0123456789ABCDEF";
	if (n >= 0)
		nbr = n;
	if (n < 0)
		nbr = (unsigned long long)n;
	if (nbr <= 15)
	{
		write (1, hexa2 + nbr, 1);
		y++;
	}
	if (nbr > 15)
	{
		y += ft_put_upcase_hexnbr(nbr / 16);
		write (1, hexa2 + nbr % 16, 1);
		y++;
	}
	return (y);
}
