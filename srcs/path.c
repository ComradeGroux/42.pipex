/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:22:10 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/30 18:02:26 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_possible_paths(char **envp)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

char	*get_path(char *cmd, char **envp)
{
	char	**possible_paths;
	char	*tmp;
	int		i;

	i = 0;
	possible_paths = get_possible_paths(envp);
	while (possible_paths[i])
	{
		tmp = ft_strjoin(possible_paths[i], cmd);
		if (!tmp)
			return (NULL);
	}
	return (possible_paths[1]);
}

static char	**ft_free_arr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	free(strs);
	return (NULL);
}

char	**parse_paths(char **possibles_paths, char *cmd)
{
	int		i;
	int		j;
	char	**new_paths;

	i = 0;
	j = 0;
	while (possibles_paths[i])
	{
		while (possibles_paths[i][j])
			j++;
		new_paths[i] = ft_calloc(j, sizeof(char));
		if (!new_paths[i])
			ft_free_arr(new_paths);
		i++;
	}
}