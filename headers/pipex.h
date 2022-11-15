/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:41:26 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/15 18:40:00 by vgroux           ###   ########.fr       */
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

# define ERROR "\033[31mError\e[0m"
# define ERR_EXEMPLE "Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n"
# define ERR_INPUT_LESS "\033[31mError: Too few argument to pipex.\e[0m\n"
# define ERR_INPUT_MUCH "\033[31mError: Too many argument to pipex.\e[0m\n"

int		err(void);
int		err_custom(char *err);
void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
char	*find_cmdfile_path(char *cmd, char **envp);
void	exe_cmd(char *argv_cmd, char **envp);
int		main(int argc, char **argv, char **arge);

#endif