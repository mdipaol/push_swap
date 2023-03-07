# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 12:05:54 by mdi-paol          #+#    #+#              #
#    Updated: 2023/03/07 14:27:25 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
LIBFT = libft/libft.a
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
SRC = Src/*.c
SRC_BONUS = Src_bonus/*.c
FLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : lf ps

lf:
	@make -sC libft
	@make bonus -sC libft

ps:
			gcc $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
			@echo "\033[1;32m✅ Compiled ✅\033[0m"

bonus: all
			gcc $(FLAGS) $(SRC_BONUS) $(GNL) $(LIBFT) -o $(NAME_BONUS)
			@echo "\033[1;32m✅ Compiled Bonus ✅\033[0m"

clean :		libclean
			rm -rf
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

libclean :
	@make clean -sC libft

fclean :	clean libfclean
			rm -rf $(NAME) $(NAME_BONUS)
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

libfclean :
			@make fclean -sC libft

re : fclean all

.SILENT:

