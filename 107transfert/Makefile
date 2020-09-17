##
## Makefile for 106bombyx in /home/bourhi_a/rendu/107transfert
## 
## Made by amine bourhime
## Login   <bourhi_a@epitech.net>
## 
## Started on  Sun Mar  2 04:40:37 2014 
## Last update Tue Mar  4 19:20:12 2014 
##

SRC		= 	src/main.c \
			src/helpers.c \
			lib/my_pow.c \
			src/put_equation.c \
			src/a_option.c \
			src/b_option.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc -lm -g

CFLAGS		=	-I./include

TMP		=	.tmp

RM		=	rm -rf

NAME		=	107transfert

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean		:
			$(RM) $(OBJ) $(TMP)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
