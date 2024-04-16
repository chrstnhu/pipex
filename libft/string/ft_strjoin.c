/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:17:03 by chrhu             #+#    #+#             */
/*   Updated: 2023/11/19 11:55:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dest;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	dest = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!dest)
// 		return (0);
// 	while (s1[j] != '\0')
// 	{
// 		dest[i] = s1[j];
// 		i++;
// 		j++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 	{
// 		dest[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;
	int		len_start;
	int		len_buff;

	if (!start)
	{
		start = (char *)malloc(1);
		if (!start)
			return (NULL);
		start[0] = '\0';
	}
	len_start = ft_strlen(start);
	len_buff = ft_strlen(buff);
	ptr = (char *)malloc(len_start + len_buff + 1);
	if (!ptr)
	{
		free(start);
		return (NULL);
	}
	ft_memcpy(ptr, start, len_start);
	ft_memcpy(ptr + len_start, buff, len_buff + 1);
	ptr[len_start + len_buff] = '\0';
	return (ptr);
}
