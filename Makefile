# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taitomer <taitomer@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 11:57:03 by taitomer          #+#    #+#              #
#    Updated: 2022/09/11 14:39:56 by taitomer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

LIBFT = make -C ./libft/

LIBFTA = ./libft/libft.a

SRC = checking.c help.c length_check.c \
	main.c paddings.c print_csp.c \
	print_dioux.c print_f.c

OBJ = checking.o help.o length_check.o \
	main.o paddings.o print_csp.o \
	print_dioux.o print_f.o

all: $(NAME)

$(NAME): $(OBJ)
	@ echo ...
	@ $(LIBFT)
	@ cp $(LIBFTA) $(NAME)
	@ gcc $(FLAGS) -c $(SRC)
	@ ar rc $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)
	@ $(LIBFT) clean

fclean: clean
	@ rm -f $(NAME)
	@ $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re
