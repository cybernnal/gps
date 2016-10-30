# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/23 16:24:51 by tbillard          #+#    #+#              #
#    Updated: 2016/05/23 16:24:52 by tbillard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	src/main.c \
	src/sort.c \
	src/dbl.c \
	src/list.c \
	src/tools.c \
	src/ope.c \
	src/check_sort.c \
	src/qs_tools.c \
	src/litle_ft.c \
	src/print.c \
	src/cut.c \
	src/freelst.c \
	src/init.c\
	src/render.c\

INC = -I ./include/ $(shell sdl2-config --cflags ) -lm

#LIB = -L./libft -lft  $(shell sdl2-config --libs)
#LIB_PATH = libft/
LIB = ft_printf/libftprintf.a $(shell sdl2-config --libs)
LIB_PATH = ft_printf/ #-L/usr/local/lib/ -lSDL2

OBJ = $(SRC:.c=.o)

FLAG = -O3# -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIB) $(INC)
	@echo "push_swap created"

%.o: %.c
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_PATH)
	@echo "push_swap cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "push_swap deleted"

re: fclean all

.PHONY: clean fclean re all
