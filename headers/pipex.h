/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:41:26 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/16 12:09:00 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include <errno.h>

# define ERROR "\033[31mError\e[0m"
# define ERR_EXEMPLE "\nEx: ./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ERR_INPUT_LESS ": Too few argument to pipex"
# define ERR_INPUT_MUCH ": Too many argument to pipex"
# define ERR_CMD_NF ": Command not found"

int		err(void);
int		err_custom(char *err);
void	init_pipe(int infile, int outfile, char **argv, char **envp);
char	*find_cmdfile_path(char *cmd, char **envp);
void	exe_cmd(char *argv_cmd, char **envp);
int		main(int argc, char **argv, char **arge);

#endif