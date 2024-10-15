/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:51:52 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/15 15:37:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Find path
char	*find_path(t_pipex *data)
{
	int		i;
	char	*exec;
	char	*tmp;

	i = 0;
	while (data->allpaths && data->allpaths[i])
	{
		tmp = ft_strjoin(data->allpaths[i], "/");
		exec = ft_strjoin(tmp, data->cmd_paths[0]);
		free(tmp);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(data->cmd_paths);
			return (exec);
		}
		free(exec);
		i++;
	}
	ft_free_tab(data->allpaths);
	ft_free_tab(data->cmd_paths);
	return (NULL);
}

//Check envp and absolute path before get path
char	*get_path(t_pipex *data, char *cmd, char **envp)
{
	char	*exec;
	char	*path_env;

	path_env = get_envp("PATH", envp);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	if (envp == NULL || *envp == NULL || path_env == NULL)
	{
		exec = ft_strjoin(path_env, cmd);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
		return (NULL);
	}
	else
	{
		data->allpaths = ft_split(path_env, ':');
		data->cmd_paths = ft_split(cmd, ' ');
		exec = find_path(data);
		return (exec);
	}
	close_fd(data, 1);
	close_fd(data, 2);
	return (NULL);
}

//Find and get envp of the PATH
char	*get_envp(char *name, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0)
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

//Initialize pipex
void	init_pipex(t_pipex *data, int argc, char **argv)
{
	data->ret_status = 0;
	data->cmd1 = argv[2];
	data->cmd2 = argv[argc - 2];
	data->infile = open(argv[1], O_RDONLY, 0644);
	data->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->infile == -1 && data->outfile == -1)
	{
		close_fd(data, 1);
		perror("\033[31mInfile");
		exit_msg("Outfile", 1);
	}
	else if (data->infile == -1)
	{
		close_fd(data, 1);
		close(data->outfile);
		exit_msg("Infile", 0);
	}
	else if (data->outfile == -1)
	{
		close_fd(data, 1);
		close(data->infile);
		exit_msg("Outfile", 1);
	}
}
