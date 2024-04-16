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

#ifndef PIPEX_H
# define PIPEX_H

# define COLOR_RED     "\033[31m"
# define COLOR_DEFAULT   "\033[0m"

# include "../libft/includes/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <time.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	child1;
	pid_t	child2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;
	char	**allpaths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*path;
	int		ret_status;
}	t_pipex;

//Free and exit
void	ft_free_tab(char **tab);
void	exit_msg(char *msg, int ret);
void	close_fd(t_pipex *data, int i);

//Check argv
void	check_argv(char **argv);

//Pipex
void	init_pipex(t_pipex *data, int argc, char **argv);
void	pipex(t_pipex *data, char **envp);
void	first_child(t_pipex *data, char **envp);
void	second_child(t_pipex *data, char **envp);
void	exec_cmd(t_pipex *data, char *cmd, char **envp);

//Find path
char	*find_path(t_pipex *data);
char	*get_path(t_pipex *data, char *cmd, char **envp);
char	*get_envp(char *name, char **envp);

#endif
