##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for 101 pong
##

SRC	=	inc/my_putchar.c	\
		inc/my_putstr.c	\
		src/movement.c \
		src/storage_management.c	\
		src/data_map.c	 \
		src/print_map.c	\
		src/boxes_management.c	\
		src/check_loose.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
