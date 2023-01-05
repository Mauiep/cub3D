NAME = cub3D

SRCS =	srcs/main.c \
		srcs/free.c \
		srcs/make_map.c \
		srcs/init_data.c \
		srcs/get_elem.c \
		srcs/utils.c \
		srcs/convert_color.c \
		srcs/gameplay.c \
		srcs/pos_player.c \
		srcs/keyboard.c \
		\
		srcs/parsing/parsing_map.c \
		srcs/parsing/check_map.c \
		srcs/parsing/parsing_elem.c \
		\
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS_DIR = objs/

OBJS =	$(SRCS:.c=.o)

OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

TFLAGS = mlx/libmlx_Linux.a -lm -lXext -lX11 libft/libft.a

$(OBJS_DIR)%.o : %.c includes/cub3D.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@mkdir -p $(OBJS_DIR)srcs/parsing
	@mkdir -p $(OBJS_DIR)gnl
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_PREFIXED)
	make -C ./libft
	@$(CC) -o $(NAME) $(OBJS_PREFIXED) $(CFLAGS) $(TFLAGS)

all: $(NAME)

clean:
	make clean -C ./libft
	@rm -rf $(OBJS_DIR)
	
fclean: clean
	make fclean -C ./libft
	@rm -f $(NAME)
	
re: fclean all

.PHONY:	all clean fclean re
