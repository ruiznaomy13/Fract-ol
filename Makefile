# ************************************************************************ #
#                                                                          #
#      ███╗   ███╗ █████╗░██╗░░██╗███████╗███████╗██╗██╗░░░░░███████╗      #
#      ████╗ ████║██╔══██╗██║░██╔╝██╔════╝██╔════╝██║██║░░░░░██╔════╝      #
#      ██╔████╔██║███████║█████═╝░█████╗░░█████╗░░██║██║░░░░░█████╗░░      #
#      ██║╚██╔╝██║██╔══██║██╔═██╗░██╔══╝░░██╔══╝░░██║██║░░░░░██╔══╝░░      #
#      ██║ ╚═╝ ██║██║  ██║██║░╚██╗███████╗██║░░░░░██║███████╗███████╗      #
#      ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚═╝╚══════╝╚══════╝      #
#                                                                          #
# ************************************************************************ #

NAME		= Fract-ol
HEADER		= fract-ol.h

INCLUDE		= -I./ -Iminilibx
SRCS_DIR 	= src
OBJ_DIR		= obj

SRCS		= $(SRCS_DIR)/main.c $(SRCS_DIR)/needs.c $(SRCS_DIR)/starts.c \
			$(SRCS_DIR)/fractales.c $(SRCS_DIR)/colors.c
OBJS		= $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(addsuffix .d,$(basename ${OBJS}))
RUTAS		= minilibx/libmlx.a

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
	@${MAKE} -C minilibx
	@${MAKE} ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${RUTAS} -framework OpenGL -framework AppKit -o ${NAME}
	@echo "$(GREEN)Fract-ol compiled$(NC)"

-include ${DEPS}

clean:
	@${MAKE} clean -C minilibx
	rm -rf ${OBJ_DIR}
	@echo "$(RED)\nDestruction successful\n$(NC)"

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re