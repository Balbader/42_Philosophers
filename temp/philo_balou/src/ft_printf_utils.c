/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kharfach <kharfach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:32:26 by kharfach          #+#    #+#             */
/*   Updated: 2023/05/01 14:55:33 by kharfach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_putaddress(unsigned long long n)
{
	char		*hexa;
	int			length;

	length = 1;
	hexa = "0123456789abcdef";
	if (n > 15)
		length += ft_putaddress(n / 16);
	write(1, &hexa[n % 16], 1);
	return (length);
}

int	conversions(int i, va_list args, const char *input)
{
	long long	address;
	int			length;

	length = 0;
	if (input[i] == '%' && input[i + 1] == 'c')
		ft_putchar(va_arg(args, int));
	if (input[i] == '%' && input[i + 1] == 'c')
		length = length + 1;
	if (input[i] == '%' && input[i + 1] == 's')
		length = length + ft_putstr_nreturn_lenght(va_arg(args, char *));
	if (input[i] == '%' && input[i + 1] == 'p')
	{
		address = (unsigned long long)va_arg(args, void *);
		if (address == 0)
		{
			write(1, "(nil)", 5);
			length = length + 5;
		}
		else
		{
			write(1, "0x", 2);
			length = length + ft_putaddress(address) + 2;
		}
	}
	return (length);
}

int	conversions_bis(int i, va_list args, const char *input)
{
	int	length;

	length = 0;
	if (input[i] == '%' && input[i + 1] == 'd')
		length = length + ft_putnbr_nreturn_lenght(va_arg(args, int));
	if (input[i] == '%' && input[i + 1] == 'i')
		length = length + ft_putnbr_nreturn_lenght(va_arg(args, int));
	if (input[i] == '%' && input[i + 1] == 'u')
		length = length
			+ ft_putnbr_unsigned_int_nreturn_lenght(va_arg(args, unsigned int));
	if (input[i] == '%' && input[i + 1] == 'x')
		length = length + ft_put_lowcase_hexnbr(va_arg(args, unsigned int));
	if (input[i] == '%' && input[i + 1] == 'X')
		length = length + ft_put_upcase_hexnbr(va_arg(args, unsigned int));
	if (input[i] == 37 && input[i + 1] == 37)
	{
		ft_putchar(37);
		length = length + 1;
	}
	return (length);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
