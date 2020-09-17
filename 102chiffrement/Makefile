##
## Makefile for Makefile for 101pong in /home/bourhi_a/rendu/math/101pong
## 
## Made by 
## Login   <bourhi_a@epitech.net>
## 
## Started on  Sun Nov 17 05:15:07 2013 
## Last update Mon Nov 25 01:23:00 2013 
##

NAME	=	conv

CC	=	gcc

RM	=	rm -f

SRC	=	conv_base/conv_functions.c \
		conv_base/convert_base.c \
		conv_base/my_getnbr.c \
		conv_base/my_power_rec.c \
		conv_base/my_putchar.c \
		conv_base/my_putstr.c \
		conv_base/my_strlen.c

OBJ	=	$(SRC:.c=.o)

all:		$(OBJ)
		$(CC) $(OBJ) -o $(NAME)
		mv $(NAME) conv_base
		cp src/102chiffrement 102chiffrement
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) conv_base/$(NAME)
		$(RM) 102chiffrement
re:		fclean all
