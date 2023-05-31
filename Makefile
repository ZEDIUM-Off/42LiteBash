CFLAGS = -Wall -Wextra -Werror
NAME = minishell
SRC = core/main.c core/builtins.c core/environment.c core/execution.c core/history.c core/prompt.c core/signals.c parsing/lexer.c parsing/parser.c parsing/tokenizer.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re