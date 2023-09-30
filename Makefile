NAME = minishell
CC = gcc
RM = rm -rf

SRCS = free_data.c handle_dollar.c handle_env.c handle_quotes.c \
init_data.c lexer.c parse_arrays.c parser.c utils.c

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