/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:41:26 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/07 16:38:18 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>

# define ERR_INPUT_LESS "Error: Too few argument to pipex.\n"
# define ERR_INPUT_MUCH "Error: Too many argument to pipex.\n"

int	main(int argc, char **argv);
int	err_msg(char *err);

#endif