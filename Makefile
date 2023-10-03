NAME = minishell
CC = gcc
RM = rm -rf

SRCS = init/free_data.c lexer/handle_dollar.c lexer/handle_env.c lexer/handle_quotes.c \
init/init_data.c lexer/lexer.c lexer/parse_arrays.c lexer/parser.c utils/utils.c \
builtin/builtin.c builtin/cd.c builtin/echo.c builtin/env.c builtin/exit.c builtin/export.c \
builtin/pwd.c builtin/unset.c error/error.c

MAIN = main.o

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJ)
	$(CC) $(OBJ) $(MAIN) -o $(NAME) -lreadline

clean:
	$(RM) $(OBJ) $(MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re