/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:08:19 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 19:43:08 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	fd[2];

	(void)argc;
	pipe(fd);
	pid = fork();
	if (pid == 0)
		child_process(fd, argv, envp);
	else
		parent_process(pid, fd, argv, envp);
	return (0);
}

t_cmd	*prepare_cmd(int fd, char *arg, char **envp)
{
	t_cmd	*cmd;

	cmd->fd = fd;
	cmd->arg = ft_split(arg, ' ');
	cmd->path = get_path(cmd->arg, envp);
	return (cmd);
}

void	child_process(int fd[], char **argv, char **envp)
{
	t_cmd	*cmd;

	cmd = prepare_cmd(0, argv[2], envp);
	cmd->fd = open(argv[1], O_RDONLY);
	dup2(cmd->fd, STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execute(cmd);
}

void	parent_process(int pid, int fd[], char **argv, char **envp)
{
	t_cmd	*cmd;

	cmd = prepare_cmd(0, argv[3], envp);
	cmd->fd = open(argv[3], O_CREAT, O_TRUNC, O_WRONLY);
	dup2(cmd->fd, STDOUT_FILENO);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	waitpid(pid, NULL, 0);
	execute(cmd);
}
