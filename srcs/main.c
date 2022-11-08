/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:40:56 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/08 16:18:30 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
		return (err_msg(ERR_INPUT_LESS));
	else if (argc > 5)
		return (err_msg(ERR_INPUT_MUCH));
	(void)argv;
	return (0);
}
