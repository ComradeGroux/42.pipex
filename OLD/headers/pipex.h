/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:41:26 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/22 17:11:38 by vgroux           ###   ########.fr       */
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
# include <errno.h>
# include <string.h>
# include "libft.h"

# define ERROR "\033[31mError\e[0m"
# define ERR_EXEMPLE "\nEx: ./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ERR_INPUT_LESS ": Too few argument to pipex"
# define ERR_INPUT_MUCH ": Too many argument to pipex"

void	err(char *name, char *err);
int		err_custom(char *err);
void	init_pipe(int infile, int outfsile, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);
char	*parse_path(char *path, char *cmd);
void	exe_cmd(char *argv_cmd, char **envp);
int		main(int argc, char **argv, char **arge);

#endif