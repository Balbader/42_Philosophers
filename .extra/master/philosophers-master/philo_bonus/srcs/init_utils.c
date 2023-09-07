/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmazoyer <jmazoyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:56:17 by jmazoyer          #+#    #+#             */
/*   Updated: 2021/10/13 11:56:17 by jmazoyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "boolean.h"

static size_t	ft_nbrlen(int nbr, int radix)
{
	size_t	length;

	length = 1;
	if (nbr < 0)
		length++;
	while (nbr / radix != 0)
	{
		nbr /= radix;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*number;

	size = ft_nbrlen(n, 10);
	number = (char *)malloc((size + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[size--] = '\0';
	number[0] = '0';
	if (n < 0)
		number[0] = '-';
	while (n != 0)
	{
		number[size--] = ((n % 10) * (-1 * (n < 0) + 1 * (n >= 0))) + '0';
		n /= 10;
	}
	return (number);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static t_bool	delete(char *s1, char *s2, int to_del)
{
	if (s1 && (to_del == 1 || to_del == 3))
		free(s1);
	if (s2 && (to_del == 2 || to_del == 3))
		free(s2);
	return (TRUE);
}

char	*ft_strjoin_del(char *s1, char *s2, int to_del)
{
	size_t	size;
	char	*dst;
	size_t	i;
	size_t	j;

	size = 0;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (!dst && delete(s1, s2, to_del))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		dst[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		dst[i++] = s2[j++];
	dst[size] = '\0';
	delete(s1, s2, to_del);
	return (dst);
}
