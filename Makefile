# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:49:40 by vgroux            #+#    #+#              #
#    Updated: 2022/11/07 14:24:08 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREENGREEN = \033[38;5;46m
RED = \033[0;31m
GREY = \033[38;5;240m
RESET = \033[0m

NAME =     pipex

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror -O3
RM =         rm -f

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/

SRCS_LIST =	

SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}%.c=${DIR_O}%.o}

# Compile la Libft
DIR_LIBFT = libft/
LIBFT_INC = -I ${DIR_LIBFT}
LIBFT =	${DIR_LIBFT}libft.a
FT_LNK = -L ${DIR_LIBFT} -l ft

LIBS = ${FT_LNK}

${NAME}: ${LIBFT} ${MLX} ${OBJS}
	@echo "$(GREENGREEN)██████╗ ██╗██████╗ ███████╗██╗  ██╗\n\
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝\n\
██████╔╝██║██████╔╝█████╗   ╚███╔╝ \n\
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ \n\
██║     ██║██║     ███████╗██╔╝ ██╗\n\
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝${RESET}"
	${CC} ${LIBS} ${OBJS} -o ${NAME}

${LIBFT}:
	@echo "[$(GREENGREEN)${NAME}$(RESET)]: Creating Libft...${GREY}"
	${MAKE} -sC ${@D}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: Libft Objects were created\n"

all: ${NAME}

${DIR_O}%.o:${DIR_S}%.c
	${CC} ${CFLAGS} -I ${DIR_H} ${LIBFT_INC} ${MLX_INC} -o $@ -c $<

clean:
	@echo "$(RED) ██████╗██╗     ███████╗ █████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗$(RESET)"
	@echo "$(RED) ██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║██║████╗  ██║██╔════╝$(RESET)"
	@echo "$(RED) ██║     ██║     █████╗  ███████║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗$(RESET)"
	@echo "$(RED) ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║██║██║╚██╗██║██║   ██║$(RESET)"
	@echo "$(RED) ╚██████╗███████╗███████╗██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝$(RESET)"
	@echo "$(RED)  ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝ $(RESET)"
	${RM} ${OBJS}

libclean:
	@echo "Clean de libft"
	${MAKE} -sC ${DIR_LIBFT} fclean

fclean: clean libclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re