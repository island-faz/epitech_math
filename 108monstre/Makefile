##
## Makefile for 107monster in /home/bourhi_a/rendu/108monstre
## 
## Made by amine bourhime
## Login   <bourhi_a@epitech.net>
## 
## Started on  Sun Mar 23 21:58:04 2014 
## Last update Wed Mar 26 03:36:09 2014 
##

SRC		= 	main.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc -lm -g

CFLAGS		=	-I./include

RM		=	rm -rf

NAME		=	108monstre

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean		:
			$(RM) $(OBJ) $(TMP)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
