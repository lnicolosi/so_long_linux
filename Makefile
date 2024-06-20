# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:28:14 by lnicolos          #+#    #+#              #
#    Updated: 2024/06/20 17:28:27 by lnicolos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SRC = $(wildcard src/*.c)
GNL = $(wildcard Get_next_line/*.c)
PRINTF = $(wildcard Printf/*.c)
OBJ = $(SRC:.c=.o) $(GNL:.c=.o) $(PRINTF:.c=.o)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c 
	$(CC) $(CFLAGS) -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

fclean:
	rm -rf $(NAME)
	rm -rf $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all


.PHONY: all clean fclean re
