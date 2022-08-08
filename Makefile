# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 15:37:29 by dpalacio          #+#    #+#              #
#    Updated: 2022/08/08 12:31:17 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -flto -pthread

INCLUDE = -I $(LIBFT_HEADERS) -I $(MLX_DIR)

LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)include/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = ./minilibx/
MLX = ./minilibx

FRAMEWORKS = -framework AppKit -framework OpenGL

LIBS = -L$(LIBFT_DIR) -lft -L$(MLX) -lmlx

HEADERS_LIST = \
	fractol.h
HEADERS_DIR = ./include/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = ./src/
SRC_LIST = \
	main.c \
	mlx.c \
	fractals_init.c \
	controls.c \
	keyboard.c \
	mouse.c \
	utils.c \
	color.c \
	screen_threads.c \
	fractals.c \
	fractals2.c
SRC = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

OBJ_DIR = ./obj/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

.PHONY = all clean fclean re

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(LIBS) $(FRAMEWORKS) $(INCLUDE) $(OBJ) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)Created object files.$(RESET)"
	@echo "$(NAME): $(GREEN)Created Fractol executable.$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)Created obj/ directory.$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDE) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Compiling Libft...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(YELLOW)Removed objects directory$(RESET)"
	@echo "$(NAME): $(YELLOW)Removed object files$(RESET)"

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@echo "$(NAME): $(YELLOW)Libft was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(YELLOW)Fractal executable was deleted$(RESET)"

re: fclean all

