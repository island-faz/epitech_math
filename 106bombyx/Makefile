##
## Makefile for 106bombyx in /home/bourhi_a/rendu/106bombyx
## 
## Made by amine bourhime
## Login   <bourhi_a@epitech.net>
## 
## Started on  Tue Feb 18 05:56:47 2014 
## Last update Tue Feb 18 09:19:51 2014 
##

SRC		= 	src/main.c \
			src/is_file.c \
			src/usage.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-I./include

TMP		=	.tmp.dat

RM		=	rm -f

NAME		=	106bombyx

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean		:
			$(RM) $(OBJ) $(TMP)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
