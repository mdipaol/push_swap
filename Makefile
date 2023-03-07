# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 12:05:54 by mdi-paol          #+#    #+#              #
#    Updated: 2023/03/06 17:58:36 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a
SRC = main.c push.c reverse_rotate.c rotate.c small_numbers.c swap.c utils.c lis.c move.c move1.c utils1.c move2.c move3.c utils2.c check.c check2.c small_numbers1.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : lf ps

lf:
	@make -sC libft
	@make bonus -sC libft

ps: $(OBJ)
			gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
			@echo "\033[1;32m✅ Compiled ✅\033[0m"

clean :		libclean
			rm -rf $(OBJ)
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

libclean :
	@make clean -sC libft

fclean :	clean libfclean
			rm -rf $(NAME)
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

libfclean :
			@make fclean -sC libft

re : fclean all

.SILENT:

