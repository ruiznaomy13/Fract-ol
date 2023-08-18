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

NAME		= fractol
HEADER		= inc/fractol.h

INCLUDE		= -I./ -I lib/libft -I lib/minilibx

OBJ_DIR		= obj/

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -O3

SRCS		= main.c masks.c needs.c fractales.c#colors.c starts.c
OBJS		= $(addprefix ${OBJ_DIR}/,$(SRCS:.c=.o))
DEPS		= $(addsuffix .d,$(basename ${OBJS}))
RUTAS		= lib/libft/libft.a lib/minilibx/libmlx.a

######## COLORS #########
GREEN		= \033[1;92m
RED			= \033[1;91m
NC			= \033[0m

${OBJ_DIR}/%.o: %.c Makefile
	@mkdir -p ${OBJ_DIR}
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@

all:
	@${MAKE} -sC lib/libft
	@${MAKE} -sC lib/minilibx
	@${MAKE} ${NAME}

${NAME}: ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} ${RUTAS} -Llib/minilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
	@echo "$(GREEN)🪐 fract-ol compiled 🪐$(NC)"

-include ${DEPS}

clean:
	@${MAKE} clean -sC lib/libft
	@${MAKE} clean -sC lib/minilibx
	rm -rf ${OBJ_DIR}
	@echo "$(RED)\nDestruction successful\n$(NC)"

fclean: clean
	@${MAKE} fclean -sC lib/libft
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re