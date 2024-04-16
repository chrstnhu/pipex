/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:51:52 by chrhu             #+#    #+#             */
/*   Updated: 2024/03/06 10:51:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Execute commande with execve
void	exec_cmd(t_pipex *data, char *cmd, char **envp)
{	
	data->cmd_args = ft_split(cmd, ' ');
	data->path = get_path(data, data->cmd_args[0], envp);
	if (data->path == NULL)
	{
		ft_free_tab(data->cmd_args);
		perror("\033[31mCommand not found, No such file or directory\033[0m");
		exit(127);
	}
	if (execve(data->path, data->cmd_args, envp) < 0)
	{
		perror("\033[31mExecve fail\033[0m");
		ft_free_tab(data->cmd_args);
		free(data->path);
		exit(1);
	}
	free(data->path);
}

// Second child (command 2)
void	second_child(t_pipex *data, char **envp)
{
	close(data->fd[1]);
	if (dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		perror("\033[31mError dup2 - failed input\033[0m");
		close(data->fd[0]);
		close(data->outfile);
		exit(1);
	}
	close(data->fd[0]);
	if (dup2(data->outfile, STDOUT_FILENO) == -1)
	{
		perror("\033[31mError dup2 - failed output\033[0m");
		close(data->outfile);
		exit(1);
	}
	close(data->outfile);
	exec_cmd(data, data->cmd2, envp);
}

// First child (command 1)
void	first_child(t_pipex *data, char **envp)
{
	close(data->fd[0]);
	if (dup2(data->infile, STDIN_FILENO) == -1)
	{
		perror("\033[31mError dup2 - failed input\033[0m");
		close(data->fd[1]);
		close(data->infile);
		exit(1);
	}
	close(data->infile);
	if (dup2(data->fd[1], STDOUT_FILENO) < 0)
	{
		perror("\033[31mError dup2 - failed output\033[0m");
		close(data->fd[1]);
		exit(1);
	}
	close(data->fd[1]);
	exec_cmd(data, data->cmd1, envp);
}

//Fork pipe and wait
void	pipex(t_pipex *data, char **envp)
{
	int	status1;
	int	status2;

	data->child1 = fork();
	if (data->child1 == -1)
		exit_msg("Error child 1 failed", 1);
	if (data->child1 == 0)
		first_child(data, envp);
	data->child2 = fork();
	if (data->child2 == -1)
		exit_msg("Error child 1 failed", 1);
	if (data->child2 == 0)
		second_child(data, envp);
	close_fd(data, 1);
	waitpid(data->child1, &status1, 0);
	waitpid(data->child2, &status2, 0);
	close_fd(data, 2);
	if (status1 != 0 && status2 == 0)
		data->ret_status = 0;
	else if (status1 != 0 || status2 != 0)
		data->ret_status = 127;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc != 5)
	{
		perror("\033[31mError need 5 arguments\033[0m");
		return (1);
	}
	else
	{
		check_argv(argv);
		if (pipe(data.fd) == -1)
			exit_msg("Error pipe failed", 1);
		init_pipex(&data, argc, argv);
		pipex(&data, envp);
		close_fd(&data, 1);
		if (data.ret_status == 127)
			exit (127);
		else if (data.ret_status == 1)
			exit (1);
	}	
	return (0);
}
