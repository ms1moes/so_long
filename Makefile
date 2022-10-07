# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msimoes- <msimoes-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 15:23:11 by msimoes-          #+#    #+#              #
#    Updated: 2022/10/04 19:14:55 by msimoes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	get_next_line_bonus.c\
		get_next_line_utils_bonus.c\
		main.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I #-fsanitize=address

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -Imlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# ^ primeira dependencia
# @ nome da regra
all: $(NAME) 

$(NAME): $(OBJS)
		@$(CC) $(^) $(MLX_FLAGS) -o $(@)

%.o: %.c
	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

$(MLX):
	make -C mlx_linux
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all