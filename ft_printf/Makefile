# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbillard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/20 13:39:20 by tbillard          #+#    #+#              #
#    Updated: 2016/04/26 16:50:37 by tbillard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAG = -Wall -Wextra

NAME = libftprintf.a 

SRC = ft_printf.c \
	  ft_sprintf.c \
	  ft_snprintf.c \
	  ldtoa.c\
	  flag.c \
	  ft_itoamax.c \
	  ft_specif.c \
	  ft_specif_nb.c \
	  ft_specif_nb2.c \
	  ft_specif_o.c \
	  ft_specif_ld.c \
	  ft_specif_bonus.c \
	  get_type.c \
	  init.c \
	  parsing.c \
	  tools.c \
	  ft_spe_l.c \
	  chartools.c \
	  bonus_tools.c \
	  ft_norm.c \
	  fc_norm.c \
	  ft_atoi.c\
	  ft_bzero.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_itoa.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strsplit.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_lstadd.c\
	  ft_strrevchr.c\
	  ft_strdupnfree.c\
	  ft_printlst.c\
	  ft_print_tab.c\
	  ft_countchiffres.c\
	  ft_freetab.c\
	  ft_nbword.c\
	  ft_sqrt.c\

SRCDIR = ./src/
SRCFILL = $(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.c=.o)
	OBJDIR = ./obj/
	OBJFILL = $(addprefix $(OBJDIR),$(OBJ))

INC = ./include

all: 		$(NAME)

$(NAME): 	$(OBJFILL)
#	@make -C libft/
	@ar rc $@ $^

$(OBJDIR)%.o:	$(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAG) -I $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean:		clean
	@rm -f $(NAME)

re: 		fclean all
