
# ---- Final Executable --- #

NAME = minishell

LIBFT = libft.a

# ---- Directories ---- #

DIR_OBJS		=	.objs/

DIR_SRC 		=	./src

DIR_LIBFT		=	src/utils/Libft/

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

FILES = src/parsing/list/src/ft_lstnew.c \
		src/parsing/list/src/ft_lstsize.c \
		src/parsing/list/src/ft_lstlast.c \
		src/parsing/list/src/ft_print_list.c \
		src/parsing/list/src/ft_lstclear.c \
		src/parsing/list/src/ft_lstadd_back.c \
		src/parsing/list/create_list.c \
		src/utils/tracker/init_track.c \
		src/utils/tracker/track.c \
		src/utils/new_str.c \
		src/utils/init_shell.c \
		src/utils/garbage_collector/gc_func.c \
		src/utils/garbage_collector/gc_init.c \
		src/utils/error_handler/exit_shell.c \
		src/utils/logger/log.c \
		src/core/init_ctx.c \
		minishell.c \
		prompt.c \

HEAD = $(shell find . -name "*.h")


OBJS	= ${addprefix ${DIR_OBJS},${FILES:.c=.o}}

# ---- Compilation ---- #

CFLAGS = -Wall -Werror -Wextra -I . -fsanitize=address -g3 -D DEBUG

# ********* RULES ******** #

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		:	$(NAME)

debug	:	 


$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force

# ---- Variables Rules ---- #

${NAME}	:	${OBJS} $(LIBFT_A)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${DIR_LIBFT} -lft -lreadline

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o:%.c ${HEAD} 
	@				$(MKDIR) $(shell dirname $@)
					${CC} ${CFLAGS} -I $(DIR_LIBFT) -I. -c $< -o $@	

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT}

clean			:
					${RM} traces.log
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

fclean_all		:	fclean fclean_lib

re				:	fclean_all
	$(MAKE) all
