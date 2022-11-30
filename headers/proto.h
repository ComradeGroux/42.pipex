/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:48:05 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 19:43:17 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

typedef struct s_cmd
{
	int		fd;
	char	**arg;
	char	*path;
}	t_cmd;

void	child_process(int fd[], char **argv, char **envp);
void	parent_process(int pid, int fd[], char **argv, char **envp);
t_cmd	*prepare_cmd(int fd, char *arg, char **envp);
char	*get_path(char **cmd, char **envp);
char	**get_possible_paths(char **envp);
char	*parse_path(char *path, char *cmd);

#endif