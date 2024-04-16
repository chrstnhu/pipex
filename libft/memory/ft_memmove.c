/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:45:42 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/17 12:25:51 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!src && !dest)
		return (0);
	if (dest < src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	return (dest);
}
