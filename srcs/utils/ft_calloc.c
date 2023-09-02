/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 08:33:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/02 08:33:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/philo.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*m;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size < nmemb || nmemb * size < size)
		return (0);
	m = (char *)malloc(nmemb * size);
	if (!m)
		return (0);
	while (i < nmemb * size)
	{
		m[i] = 0;
		i++;
	}
	return ((void *) m);
}
