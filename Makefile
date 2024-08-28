##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##

SRC =	$(wildcard ./src/*.c) \
		$(wildcard ./lib/*.c)

OBJ =	$(SRC:.c=.o)

NAME = mysh

CFLAGS = -I./include -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -g3

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
