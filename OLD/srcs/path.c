/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:42:24 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/22 17:06:29 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	char	*path;
	char	*exe;
	int		i;
	int		j;

	j = 0;
	path = NULL;
	while (envp[j] && ft_strncmp("PATH=", envp[j], 5))
		j++;
	if (!envp[j])
		return (cmd);
	path = envp[j] + 5;
	i = 0;
	while (path[i])
	{
		if (path[i] == ':' || i == 0)
		{
			exe = parse_path(&(path[i]), cmd);
			if (access(exe, F_OK))
				return (exe);
			free(exe);
		}
		i++;
	}
	return (cmd);
}

char	*parse_path(char *path, char *cmd)
{
	char	*exe;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (path[i] && path[i] != ':')
		i++;
	tmp = ft_calloc(i + 2, sizeof(char));
	if (!tmp)
		exit(0);
	j = 0;
	while (path[j] && path[j] != ':')
		tmp[i++] = path[j++];
	tmp[i] = '/';
	exe = ft_strjoin(tmp, cmd);
	free(tmp);
	return (exe);
}
