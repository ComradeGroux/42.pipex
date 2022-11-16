/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:23:17 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/15 21:49:33 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	err(void)
{
	perror(ERROR);
	exit(1);
}

int	err_custom(char *err)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd(ERR_EXEMPLE, 2);
	exit(1);
}
