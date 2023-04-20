SRCS		=	$(SRCS_DIR)/get_next_line.c\
				$(SRCS_DIR)/get_next_line_utils.c\
				$(SRCS_DIR)/map_size.c\
				$(SRCS_DIR)/map_utils.c\
				$(SRCS_DIR)/checkers.c\
				$(SRCS_DIR)/render_map.c\
				$(SRCS_DIR)/movement.c\
				$(SRCS_DIR)/hooks.c\
				$(SRCS_DIR)/close_game.c\
				$(SRCS_DIR)/main.c\


SRCS_DIR	= srcs

OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	= objs

MLX			= mlx_linux/libmlx_Linux.a

PRINTF		= printf/libftprintf.a

LIBFT		= libft/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -fr
NAME		= so_long

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I headers -I printf/ -I libft/ -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(LIBFT) $(PRINTF) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lprintf -lftprintf -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	make -C mlx_linux

$(PRINTF):
	make -C printf

$(LIBFT):
	make -C libft

clean:
			$(RM)	$(OBJS)
			make clean -C  printf
			make clean -C  libft
			make clean -C  mlx_linux

fclean:	clean
			$(RM)	$(NAME) $(OBJS_DIR)
			make fclean -C  printf
			make fclean -C  libft

re:	fclean all

.PHONY: fclean all re clean