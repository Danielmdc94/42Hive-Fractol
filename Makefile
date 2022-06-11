# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 15:37:29 by dpalacio          #+#    #+#              #
#    Updated: 2022/06/09 17:56:50 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

CFLAGS = -Wall -Wextra -Werror -flto -lpthread

INCLUDES = -I ./libft/ -I ./minilibx #-I /usr/local/include

LIBFT = -L ./libft -lft #-L /usr/local/lib/ -lmlx

MINXLIB = -L ./minilibx -lmlx -framework AppKit -framework OpenGL


#FW = -framework OpenGL -framework AppKit

SRC = main.c mlx.c fractals_init.c controls.c keyboard.c mouse.c \
	  utils.c color.c screen_threads.c fractals.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	$(CC) $(INCLUDES) $(SRC) $(MINXLIB) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	@make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
