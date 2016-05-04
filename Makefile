#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaudin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 09:51:13 by sgaudin           #+#    #+#              #
#    Updated: 2016/05/04 10:04:34 by sgaudin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

L = lib_draw_img/

CC = gcc -Wall -Wextra -Werror

CC_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC = src/main.c src/mandelbrot.c src/key_hook.c

LIBD_SRC = $(L)put_pixel_img.c

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CC_FLAGS) $(SRC) $(LIBD_SRC) -o $(NAME) -I./includes -L./libft/ -lft

clean:
	make -C libft/ clean

fclean:
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all