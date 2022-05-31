# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 15:37:29 by dpalacio          #+#    #+#              #
#    Updated: 2022/05/31 15:58:15 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

CFLAGS = -Wall -Wextra -Werror -flto -lpthread

INCLUDES = -I ./libft/ -I /usr/local/include

LIB = -L ./libft -lft -L /usr/local/lib/ -lmlx

FW = -framework OpenGL -framework AppKit

SRC = main.c mlx.c julia.c burning_ship.c controls.c keyboard.c mouse.c utils.c color.c screen_threads.c fractals.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	$(CC) $(INCLUDES) $(SRC) $(LIB) $(FW) -o $(NAME)

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
