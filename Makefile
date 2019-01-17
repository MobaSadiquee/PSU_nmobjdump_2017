##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make nm and obj
##

CC	= gcc

RM	= rm -rf

NAME1	= my_nm

NAME2	= my_objdump

SRC1	= ./nm/my_error.c	\
	  ./nm/my_basic_func.c	\
	  ./nm/nm_32.c		\
	  ./nm/my_func_32.c	\
	  ./nm/nm_64.c		\
	  ./nm/my_func_64.c	\
	  ./nm/main.c

SRC2	= ./objdump/my_error.c		\
	  ./objdump/my_basic_func.c	\
	  ./objdump/objdump_32.c	\
	  ./objdump/objdump_64.c	\
	  ./objdump/my_func_32.c	\
	  ./objdump/my_func_64.c	\
	  ./objdump/main.c 

OBJ1	= $(SRC1:.c=.o)

OBJ2	= $(SRC2:.c=.o)

CFLAGS	+= -I./include -I. -W -Wall -Wextra

LDFLAGS1 = -o $(NAME1)

LDFLAGS2 = -o $(NAME2)

all:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
	$(CC) $(LDFLAGS1) $(OBJ1)

$(NAME2):       $(OBJ2)
	$(CC) $(LDFLAGS2) $(OBJ2)

nm:		$(NAME1)

objdump:	$(NAME2)

clean:
	$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	$(RM) $(NAME1) $(NAME2)

re:	fclean all
