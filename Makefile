# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpalumbo <fpalumbo@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:14:46 by jfazi             #+#    #+#              #
#    Updated: 2024/05/07 15:07:04 by fpalumbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
SRCS = main.c \
	inputs.c \
	init.c \
	init2.c \
	player.c \
	player2.c \
	map.c \
	get_next_line.c \
	direction.c \
	vector2.c \
	raycast.c \
	rendering.c \
	rendering2.c \
	minimap.c \
	parsing.c \
	parsing2.c \
	parsing3.c \
	parsing4.c \
	parsing5.c \
	parsing6.c \
	free.c \
	free2.c
	
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lftprintf
MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a

RM = rm -f

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT_LIB) $(MINILIBX_LIB) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)
$(MINILIBX_LIB):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAGS) -Lmlx_linux -lmlx_Linux -L$(MINILIBX_DIR) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I -Imlx_linux -O3 -c $< -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
