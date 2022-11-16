/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:40:56 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/16 12:09:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;

	if (argc < 5)
		err_custom(ERR_INPUT_LESS);
	else if (argc > 5)
		err_custom(ERR_INPUT_MUCH);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		err();
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00664);
	if (outfile == -1)
		err();
	init_pipe(infile, outfile, argv, envp);
	return (0);
}

void	init_pipe(int infile, int outfile, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		err();
	pid = fork();
	if (pid == -1)
		err();
	if (pid == 0)
	{
		dup2(infile, STDIN_FILENO);
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exe_cmd(argv[3], envp);
	}
	else
	{
		dup2(outfile, STDOUT_FILENO);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		exe_cmd(argv[4], envp);
	}
}
