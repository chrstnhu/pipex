/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:43:00 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/17 16:03:45 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
		{
			count++;
			s++;
		}
	}
	return (count);
}

//Don t forget to free
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**result;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			j = 0;
			while (*s && *s != c)
			{
				j++;
				s++;
			}
			result[i++] = ft_substr(s - j, 0, j);
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}
