#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 09:51:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/05/03 09:54:45 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CC = gcc -Wall -Wextra -Werror

CC_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/test.c

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CC_FLAGS) $(SRC) -o $(NAME) -I./includes -L./libft/ -lft

clean:
	make -C libft/ clean

fclean:
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all