/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:36:32 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/17 13:38:09 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			str = ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char)c)
		str = ((char *)(s + i));
	return (str);
}
