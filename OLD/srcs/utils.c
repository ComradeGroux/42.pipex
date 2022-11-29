/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:53:07 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/22 17:37:05 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe_cmd(char *argv_cmd, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	if (argv_cmd)
	{
		cmd = ft_split(argv_cmd, ' ');
		if (!ft_strchr(cmd[0], '/'))
		{
			path = get_path(cmd[0], envp);
			execve(path, cmd, envp);
			err(cmd[0], "command not found");
		}
		else
		{
			path = cmd[0];
			if (access(path, X_OK))
				err(path, strerror(errno));
			else
				execve(path, cmd, envp);
		}
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
	}
	exit(0);
}
