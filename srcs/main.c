/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:08:19 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/06 12:13:29 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "proto.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	fd[2];

	if (argc == 5)
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
			child_process(fd, argv, envp);
		else
			parent_process(pid, fd, argv, envp);
	}
	return (1);
}

void	execute(t_cmd *cmd, char **envp)
{
	if (ft_strchr(cmd->arg[0], '/'))
		cmd->path = cmd->arg[0];
	if (!access(cmd->path, X_OK))
		execve(cmd->path, cmd->arg, envp);
	perror("");
}

void	prepare_cmd(t_cmd	*cmd, int fd, char *arg, char **envp)
{
	cmd->fd = fd;
	cmd->arg = ft_split(arg, ' ');
	cmd->path = get_path(cmd->arg[0], envp);
}

void	child_process(int fd[], char **argv, char **envp)
{
	t_cmd	cmd;

	(void)fd;
	prepare_cmd(&cmd, 0, argv[2], envp);
	cmd.fd = open(argv[1], O_RDONLY);
	if (cmd.fd == -1)
	{
		perror(argv[1]);
		return ;
	}
	dup2(cmd.fd, STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	execute(&cmd, envp);
}

void	parent_process(int pid, int fd[], char **argv, char **envp)
{
	t_cmd	cmd;

	prepare_cmd(&cmd, 0, argv[3], envp);
	cmd.fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY);
	if (cmd.fd == -1)
	{
		perror(argv[4]);
		exit(127);
	}
	dup2(cmd.fd, STDOUT_FILENO);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	waitpid(pid, NULL, 0);
	execute(&cmd, envp);
}
