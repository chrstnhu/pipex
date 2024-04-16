/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:28:05 by chrhu             #+#    #+#             */
/*   Updated: 2023/12/12 16:13:01 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*next_fd(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	line = (char *)malloc(ft_strlen(save) - i + 1);
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (save[i + j])
	{
		line[j] = save[i + j];
		j++;
	}
	line[j] = '\0';
	free(save);
	return (line);
}

static char	*line_fd(char *save)
{
	char	*line;
	int		i;

	if (!save || !save[0])
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*read_fd(int fd, char *save)
{
	char	*buffer;
	int		nbytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nbytes = read(fd, buffer, BUFFER_SIZE);
	if (nbytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	while (nbytes > 0)
	{
		buffer[nbytes] = '\0';
		save = ft_strjoin(save, buffer);
		if (ft_strchr(save, '\n'))
			break ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd == -42)
	{
		free(save);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_fd(fd, save);
	if (!save)
		return (NULL);
	line = line_fd(save);
	save = next_fd(save);
	return (line);
}
