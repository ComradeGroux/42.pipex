# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:49:40 by vgroux            #+#    #+#              #
#    Updated: 2022/11/30 17:24:11 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREENGREEN = \033[38;5;46m
RED = \033[0;31m
GREY = \033[38;5;240m
RESET = \033[0m

NAME =     pipex

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror
RM =         rm -rf

DIR_H = headers/
DIR_S =	srcs/
DIR_O =	objs/

SRCS_LIST =	main.c \
			path.c

SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}%.c=${DIR_O}%.o}

# Compile la Libft
DIR_LIBFT = libft/
LIBFT_INC = -I ${DIR_LIBFT}
LIBFT =	${DIR_LIBFT}libft.a
FT_LNK = -L ${DIR_LIBFT} -l ft

LIBS = ${FT_LNK}

${NAME}: title ${LIBFT} createobjs ${OBJS}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: Pipex Objects were created"
#	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: Link of the Objects${GREY}"
	${CC} ${OBJS} ${LIBS} -o ${NAME}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: Pipex created !${GREY}"


title:
	@echo "$(GREENGREEN)██████╗ ██╗██████╗ ███████╗██╗  ██╗\n\
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝\n\
██████╔╝██║██████╔╝█████╗   ╚███╔╝ \n\
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ \n\
██║     ██║██║     ███████╗██╔╝ ██╗\n\
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝${RESET}"

createobjs:
	@echo "[$(GREENGREEN)${NAME}$(RESET)]: Creating Pipex Objects...${GREY}"
	@mkdir -p ${DIR_O}

${LIBFT}:
	@echo "[$(GREENGREEN)${NAME}$(RESET)]: Creating Libft...${GREY}"
	${MAKE} -C ${@D}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: Libft Objects were created"

all: ${NAME}

${DIR_O}%.o:${DIR_S}%.c
	${CC} ${CFLAGS} ${LIBFT_INC} -I ${DIR_H} -o $@ -c $<

clean:
	@echo "$(RED) ██████╗██╗     ███████╗ █████╗ ███╗   ██╗██╗███╗   ██╗ ██████╗$(RESET)"
	@echo "$(RED) ██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║██║████╗  ██║██╔════╝$(RESET)"
	@echo "$(RED) ██║     ██║     █████╗  ███████║██╔██╗ ██║██║██╔██╗ ██║██║  ███╗$(RESET)"
	@echo "$(RED) ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║██║██║╚██╗██║██║   ██║$(RESET)"
	@echo "$(RED) ╚██████╗███████╗███████╗██║  ██║██║ ╚████║██║██║ ╚████║╚██████╔╝$(RESET)"
	@echo "$(RED)  ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝ ╚═════╝ $(RESET)"
	@echo "$(RESET)[$(RED)${NAME}$(RESET)]: Clean Pipex Objects...${GREY}"
	${RM} ${DIR_O}
	@echo "$(RESET)[$(RED)${NAME}$(RESET)]: Pipex Objects were cleaned"

libclean:
	@echo "$(RESET)[$(RED)${NAME}$(RESET)]: Clean libft...${GREY}"
	${MAKE} -C ${DIR_LIBFT} fclean
	@echo "$(RESET)[$(RED)${NAME}$(RESET)]: Libft were cleaned"

fclean: clean libclean
	@echo "$(RESET)[$(RED)${NAME}$(RESET)]: Clean Pipex...${GREY}"
	${RM} ${NAME}
	@echo "$(RESET)[$(RED)${NAME}$(RESET)]: Pipex was cleaned...${GREY}"

re: fclean all

.PHONY: all clean fclean re