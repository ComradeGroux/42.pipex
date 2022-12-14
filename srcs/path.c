/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:22:10 by vgroux            #+#    #+#             */
/*   Updated: 2022/12/13 18:29:30 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	char	**possible_paths;
	int		i;

	i = 0;
	possible_paths = get_possible_paths(envp);
	while (possible_paths[i])
	{
		possible_paths[i] = parse_path(possible_paths[i], cmd);
		if (!possible_paths[i])
			return (free_arr(possible_paths));
		if (!access(possible_paths[i], F_OK))
			return (possible_paths[i]);
		i++;
	}
	return (free_arr(possible_paths));
}

char	**get_possible_paths(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

char	*parse_path(char *path, char *cmd)
{
	int		i;
	char	*new_path;

	i = 0;
	new_path = ft_calloc(ft_strlen(path) + 2, sizeof(char));
	if (!new_path)
	{
		free(path);
		return (NULL);
	}
	while (path[i])
	{
		new_path[i] = path[i];
		i++;
	}
	new_path[i] = '/';
	new_path = ft_gnl_strjoin(new_path, cmd);
	return (new_path);
}

char	*free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr[i]);
	free(arr);
	return (NULL);
}
