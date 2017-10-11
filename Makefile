# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/29 22:25:39 by mlegeay           #+#    #+#              #
#    Updated: 2017/05/30 00:36:08 by mlegeay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = libftprintf.a

SRC_NAME =	ft_flags.c\
			ft_check.c\
			ft_end.c\
			ft_display.c\
			ft_divers.c\
			ft_init.c\
			ft_precision.c\
			ft_printf_c.c\
			ft_printf_d.c\
			ft_printf_undefined.c\
			ft_printf_p.c\
			ft_printf_s.c\
			ft_printf_wowu.c\
			ft_printf_ou.c\
			ft_printf_x.c\
			ft_printf.c\
			ft_buf.c\
			ft_wchar_in_char.c\
			ft_width_char.c\
			ft_width_num.c\
			ft_match_specifier.c\
			ft_atoi.c\
			ft_isdigit.c\
			ft_itoa_base.c\
			ft_strlen.c\
			ft_strsub.c\
			ft_strlwr.c\
			ft_wstrlen.c\
			ft_wstrsub.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix , $(SRC_NAME))
INC = $(addprefix , $(INC_NAME))
OBJ = $(addprefix ,$(OBJ_NAME))
OBJLIB = $(addprefix ,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	ar rc $(NAME) $(OBJ) $(OBJLIB)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	rm -rf ./obj $(NAME)

re: fclean all

norme:
	norminette $(SRC) $(LIB) $(INC)
