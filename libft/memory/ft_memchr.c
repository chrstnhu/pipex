/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:40:43 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/17 13:17:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char const	*ptr;

	i = 0;
	ptr = (unsigned char const *)s;
	while (i < n)
	{
		if (*(ptr + i) == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (0);
}
