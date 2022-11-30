NAME = cub3D

SRCS =	srcs/main.c \
		srcs/make_map.c \
		srcs/free.c \
		\
		srcs/parsing/parsing_map.c \
		srcs/parsing/check_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS_DIR = objs/

OBJS =	$(SRCS:.c=.o)

OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

TFLAGS = libft/libft.a

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
