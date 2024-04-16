/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:51:52 by chrhu             #+#    #+#             */
/*   Updated: 2024/03/06 10:51:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//Close files
void	close_fd(t_pipex *data, int i)
{
	if (i == 1)
	{
		close(data->fd[0]);
		close(data->fd[1]);
	}
	else if (i == 2)
	{
		close(data->infile);
		close(data->outfile);
	}
}

//Exit message with perror
void	exit_msg(char *msg, int ret)
{
	ft_printf("%s", COLOR_RED);
	perror(msg);
	ft_printf("%s", COLOR_DEFAULT);
	exit(ret);
}

//Free tab
void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

//Check if argv[2] & argv[3] is empty
void	check_argv(char **argv)
{
	if (!argv[2] || !argv[3] || ((argv[2][0] == '\0' || argv[2][1] == '\0')
		&& (argv[3][0] == '\0' || argv[3][1] == '\0')))
	{
		perror("\033[31mCommand not found");
		exit_msg("Command not found", 127);
	}
	if (!argv[2] || argv[2][0] == '\0' || argv[2][1] == '\0')
		exit_msg("Command not found", 0);
	if (!argv[3] || argv[3][0] == '\0' || argv[3][1] == '\0')
		exit_msg("Command not found", 127);
}
