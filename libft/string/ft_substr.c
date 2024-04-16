/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:16:07 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/17 16:00:32 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	len_str;

	i = 0;
	if (!s)
		return (0);
	len_str = ft_strlen(s);
	if (start > len_str)
		return (ft_strdup(""));
	if (len_str < len + start)
		len = len_str - start;
	ptr = (char *) malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (0);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
