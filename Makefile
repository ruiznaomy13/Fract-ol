# ************************************************************************* #
#                                                                           #
#		███╗   ███╗ █████╗░██╗░░██╗███████╗███████╗██╗██╗░░░░░███████╗		#
#		████╗ ████║██╔══██╗██║░██╔╝██╔════╝██╔════╝██║██║░░░░░██╔════╝		#
#		██╔████╔██║███████║█████═╝░█████╗░░█████╗░░██║██║░░░░░█████╗░░		#
#		██║╚██╔╝██║██╔══██║██╔═██╗░██╔══╝░░██╔══╝░░██║██║░░░░░██╔══╝░░		#
#		██║ ╚═╝ ██║██║  ██║██║░╚██╗███████╗██║░░░░░██║███████╗███████╗		#
#		╚═╝     ╚═╝╚═╝  ╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚══════╝╚══════╝		#
#                                                                     		#
# *************************************************************************	#

NAME		= fract-ol
HEADER		= fract-ol.h

INCLUDE		= -I./ -I inc/libft -Iminilibx
SRCS_DIR 	= src
OBJ_DIR		= obj

SRCS		= $(SRCS_DIR)/main.c
OBJS		= $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(addsuffix .d,$(basename ${OBJS}))
RUTAS		= inc/libft/libft.a minilibx/libmlx.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

######## COLORS #########
GREEN		= \033[1;92m
RED			= \033[1;91m
NC			= \033[0m

${OBJ_DIR}/%.o: %.c Makefile
	@mkdir -p ${OBJ_DIR}
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:
	@${MAKE} -C inc/libft
	@${MAKE} -C minilibx
	@${MAKE} ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${RUTAS} -framework OpenGL -framework AppKit -o ${NAME}
	@echo "$(GREEN)push_swap compiled$(NC)"

-include ${DEPS}

clean:
	@${MAKE} clean -C inc/libft
	@${MAKE} clean -C minilibx
	rm -rf ${OBJ_DIR}
	@echo "$(RED)\nDestruction successful\n$(NC)"

fclean: clean
	@${MAKE} fclean -C inc/libft
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re