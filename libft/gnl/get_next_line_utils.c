/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:28:21 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/14 12:15:39 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s || *s == '\0')
		return (NULL);
	while (*s != '\0' && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)(s));
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *) src)[i];
		i++;
	}
	return (dest);
}
/*
char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;
	size_t	len_start;
	size_t	len_buff;

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
	free(start);
	return (ptr);
}


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
	free(start);
	return (ptr);
}*/
