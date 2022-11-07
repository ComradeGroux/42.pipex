# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 14:09:53 by vgroux            #+#    #+#              #
#    Updated: 2022/10/31 18:40:14 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror
RM =         rm -f

SRCS =		get_next_line_bonus.c get_next_line_utils_bonus.c ft_printf_ptr.c ft_printf.c ft_printf_utils.c ft_ulltoa.c ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstnew_bonus.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_tolower.c ft_toupper.c ft_strnstr.c ft_bzero.c ft_strlcat.c ft_strlcpy.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memset.c ft_calloc.c ft_strdup.c ft_strlen.c ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c
OBJS =		${SRCS:.c=.o}

NAME =     libft.a

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
