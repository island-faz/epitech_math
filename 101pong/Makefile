##
## Makefile for Makefile for 101pong in /home/bourhi_a/rendu/math/101pong
## 
## Made by 
## Login   <bourhi_a@epitech.net>
## 
## Started on  Sun Nov 17 05:15:07 2013 
## Last update Sun Nov 17 16:09:18 2013 
##

NAME	=	101pong

CC	=	gcc

RM	=	rm -rf

SRC	=	lib/my_getnbr.c \
		lib/my_putstr.c \
		lib/my_put_nbr.c \
		101pong.c

OBJ	=	$(SRC:.c=.o)

all:		$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -lm

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
