##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

CPPFLAGS=	-iquote include/

CFLAGS	=	-Wall -Wextra

CC		?=	gcc

RM		?=	rm -f

SRC		=	src/main.c						\
			src/str_to_arr.c					\
			src/loop.c						\
			src/forward_speed.c					\
			src/turn.c						\
			src/retrieve_current_speed.c				\
			src/error_code.c					\
			src/dist_speed_arrays.c

OBJ		=	$(SRC:.c=.o)

NAME	=	ai

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g3
debug: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
