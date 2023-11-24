# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 10:10:14 by bfaure            #+#    #+#              #
#    Updated: 2023/11/24 15:37:37 by bfaure           ###   ########lyon.fr    #
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

FILES =	src/utils/list/dlst_add.c  \
				src/utils/list/dlst_del.c  \
				src/utils/list/lst_base_func.c \
				src/utils/list/lst_set_get.c \
				src/utils/list/dlst_base_func.c \
				src/utils/list/dlst_set_get.c  \
				src/utils/list/lst_add.c  \
				src/utils/list/lst_del.c  \
				src/parsing/syntax/syntax_check.c \
				src/parsing/syntax/control_meta.c \
				src/parsing/utils/get_meta.c \
				src/utils/init_shell.c \
				src/utils/garbage_collector/gc_func.c \
				src/utils/garbage_collector/gc_init.c \
				src/utils/error_handler/exit_shell.c \
				src/utils/error_handler/get_error_msg.c \
				src/utils/error_handler/handle_error.c \
				src/utils/ft_strinsert.c \
				src/core/init_ctx.c \
				minishell.c \
				prompt.c \
				src/parsing/pars_line.c \
				src/parsing/utils/quotes_utils.c \
				src/parsing/pars_paths.c \
				src/parsing/pars_env.c \
				src/parsing/split_parse.c \
				src/parsing/utils/free_split_line.c \
				src/parsing/fill_struct/block.c \
				src/parsing/fill_struct/cmd.c \
				src/parsing/fill_struct/check_builtins.c \
				src/parsing/fill_struct/status_env.c	\
				src/parsing/fill_struct/check_cmd.c	\
				src/parsing/pipeline/parse_pipe.c\
				src/parsing/pipeline/parse_redirect.c\
				src/parsing/pipeline/pipeline.c \
				src/parsing/new_file.c \
				src/parsing/utils/skip_to_space.c \
				src/parsing/expand.c \
				src/utils/clean_blocks.c \
				src/utils/hist_handler.c \
				src/builtins/echo.c \
				src/core/handle_sig.c \
				src/builtins/pwd.c \
				src/builtins/cd.c \
				src/builtins/exit.c \
				src/builtins/export/export.c \
				src/builtins/export/export_cmd.c \
				src/builtins/export/export_utils.c \
				src/builtins/unset.c \
				src/core/execution/exec_cmd.c \
				src/core/files.c \
				src/core/execution/run_pipeline.c \
				src/core/execution/exec_utils.c \
				src/core/execution/run_pipeline_utils.c \
				src/core/execution/process_utils.c \
				src/core/execution/exec_redir_handle.c \
				src/core/execution/here_doc_handler.c \
				src/builtins/run_builtin.c \
				src/builtins/export/export_utils.c \
				src/builtins/export/print_export.c \
				src/utils/list/lst_check.c \
				src/parsing/make_env/make_env.c \
				src/parsing/make_env/make_env_utils.c \

HEAD = 	./src/parsing/pipeline/pipeline.h \
		./src/parsing/syntax/syntax.h \
		./src/parsing/fill_struct/fill_struct.h \
		./src/parsing/parsing.h \
		./src/builtins/builtins.h \
		./src/utils/utils.h \
		./src/utils/error_handler/error_handler.h \
		./src/utils/list/list.h \
		./src/utils/Libft/headers/get_next_line.h \
		./src/utils/Libft/headers/libft.h \
		./src/utils/Libft/headers/ft_printf.h \
		./src/utils/garbage_collector/garbage.h \
		./src/core/core.h \
		./src/core/execution/execution.h \
		./src/types/types.h \
		./src/types/enums.h \
		./minish.h \

INC = -I. -I$(DIR_LIBFT)

OBJS	= ${addprefix ${DIR_OBJS},${FILES:.c=.o}}

# ---- Compilation ---- #

CFLAGS = -Wall -Werror -Wextra #$(DEB_FLAGS) 

DEB_FLAGS = -g3 -fsanitize=address

# ********* RULES ******** #

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		:	$(NAME)

run		:	all
			./${NAME}

leaks:    all
		@${RM} valgrind.txt 
		echo "{" > valgrind_ignore_leaks.txt
		echo "leak readline" >> valgrind_ignore_leaks.txt
		echo "    Memcheck:Leak" >> valgrind_ignore_leaks.txt
		echo "    ..." >> valgrind_ignore_leaks.txt
		echo "    fun:readline" >> valgrind_ignore_leaks.txt
		echo "}" >> valgrind_ignore_leaks.txt
		echo "{" >> valgrind_ignore_leaks.txt
		echo "    leak add_history" >> valgrind_ignore_leaks.txt
		echo "    Memcheck:Leak" >> valgrind_ignore_leaks.txt
		echo "    ..." >> valgrind_ignore_leaks.txt
		echo "    fun:add_history" >> valgrind_ignore_leaks.txt
		echo "}" >> valgrind_ignore_leaks.txt
		valgrind --suppressions=valgrind_ignore_leaks.txt --leak-check=full \
			--show-leak-kinds=all --track-fds=yes \
			--show-mismatched-frees=yes --read-var-info=yes \
			--log-file=valgrind.txt -s --trace-children=yes ./${NAME}

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

.PHONY:	all clean fclean re fclean_lib force

# ---- Variables Rules ---- #

${NAME}	:	${OBJS} $(LIBFT_A)
			${CC} ${CFLAGS} $(INC) $^ -lreadline -o $@

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o:%.c $(HEAD)
	@				$(MKDIR) $(shell dirname $@)
					${CC} ${CFLAGS} $(INC) -c $<  -o $@

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT} -j4

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean fclean_lib
					${RM} ${NAME}

re				:	fclean
	$(MAKE) all
