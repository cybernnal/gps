# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/23 16:24:51 by tbillard          #+#    #+#              #
#    Updated: 2016/10/26 18:26:32 by tbillard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = psy

SRC =	src/main.c \
	src/sort.c \
	src/dbl.c \
	src/list.c \
	src/ope.c \
	src/init.c\
	src/render.c\

INC = -I ./include/ -I ./libft $(shell sdl2-config --cflags ) -lm

LIB = -L./libft -lft  $(shell sdl2-config --libs)
LIB_PATH = libft/

OBJ = $(SRC:.c=.o)

FLAG = -O3 -Ofast

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(INC)
	@echo "psy created"

%.o: %.c
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "psy cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "psy deleted"

re: fclean all

.PHONY: clean fclean re all
