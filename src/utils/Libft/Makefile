# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:23:52 by bfaure            #+#    #+#              #
#    Updated: 2023/05/08 16:20:50 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_strchr.c\
	ft_strlen.c\
	ft_strlen_int.c\
	ft_strlen_line.c\
	ft_strrchr.c\
	ft_bzero.c\
	ft_isascii.c\
	ft_memchr.c\
	ft_memmove.c\
	ft_strlcat.c\
	ft_strncmp.c\
	ft_tolower.c\
	ft_isalnum.c\
	ft_isdigit.c\
	ft_memcmp.c\
	ft_memset.c\
	ft_strlcpy.c\
	ft_strnstr.c\
	ft_toupper.c\
	ft_atoi.c\
	ft_atoll.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strfjoin.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_printf.c \
	ft_putchar_printf.c\
	ft_putnbr_base_printf.c\
	ft_putnbr_printf.c\
	ft_putptr_printf.c\
	ft_putstr_printf.c\
	get_next_line.c\
	get_next_line_utils.c\

DIR_SRCS = src/

DIR_OBJS = .objs/

DIR_HEAD = headers/

OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

CC = cc

MKDIR = mkdir -p

HEADERS	= 	libft.h\
			get_next_line.h\
			ft_printf.h\

CFLAGS	= -Wall -Wextra -Werror

all :		${NAME}

clean :
			rm -rf ${DIR_OBJS}

fclean :	clean
			rm -rf ${NAME}

re :		fclean
			$(MAKE) all

${DIR_OBJS}%.o: 	${DIR_SRCS}%.c	${addprefix ${DIR_HEAD}, ${HEADERS}} | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${DIR_HEAD} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}

.PHONY:		all clean fclean re