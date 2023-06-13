# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 10:10:14 by bfaure            #+#    #+#              #
#    Updated: 2023/06/13 11:44:32 by  mchenava        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- Final Executable --- #

NAME = minishell

LIBFT = libft.a

# ---- Directories ---- #

DIR_OBJS		=	.objs/

DIR_SRC 		=	./src

DIR_LIBFT		=	src/utils/Libft/

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

FILES =	src/parsing/list/dlst_add.c  \
				src/parsing/list/dlst_del.c  \
				src/parsing/list/lst_base_func.c \
				src/parsing/list/lst_set_get.c \
				src/parsing/list/dlst_base_func.c \
				src/parsing/list/dlst_set_get.c  \
				src/parsing/list/lst_add.c  \
				src/parsing/list/lst_del.c  \
				src/parsing/syntax/syntax_check.c \
				src/parsing/syntax/control_meta.c \
				src/parsing/get_meta.c \
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
				src/parsing/ft_read.c \
				src/parsing/reading_mode.c \
				src/parsing/pars_line.c \
				src/parsing/pars_env.c \
				src/parsing/split_parse.c \


HEAD = $(shell find . -name "*.h")

INC = -I. -I$(DIR_LIBFT)

OBJS	= ${addprefix ${DIR_OBJS},${FILES:.c=.o}}

# ---- Compilation ---- #

CFLAGS = -Wall -Werror -Wextra $(DEB_FLAGS)

DEB_FLAGS = -g3 -fsanitize=address

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
			${CC} ${CFLAGS} $(INC) $^ -lreadline  -o $@

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o:%.c ${HEAD} 
	@				$(MKDIR) $(shell dirname $@)
					${CC} ${CFLAGS} $(INC) -c $<  -o $@

watch : $(DIR_SRC)
	fswatch -o $^ | make && ./$(NAME)

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT} -j4

clean			:
					${RM} traces.log
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

fclean_all		:	fclean fclean_lib

re				:	fclean_all
	$(MAKE) all
