/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:22:10 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/29 18:36:19 by vgroux           ###   ########.fr       */
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

	possible_paths = get_possible_paths(envp);
}