# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 12:05:54 by mdi-paol          #+#    #+#              #
#    Updated: 2023/02/22 10:47:58 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a
SRC = main.c push.c reverse_rotate.c rotate.c small_numbers.c swap.c utils.c lis.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -g

all : $(NAME_SERVER)

$(NAME_SERVER) : lf push_swap

lf:
			@make -C libft

push_swap: $(OBJ)
			gcc $(FLAGS) $(SRC) $(Libft) -o $(NAME)

clean :		libclean
			rm -rf $(OBJ)

libclean :
			@make clean -C libft

fclean :		clean libfclean
			rm -rf $(NAME)

libfclean :
			@make fclean -C libft

re : fclean all
