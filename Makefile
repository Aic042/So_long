NAME	= so_long
LIBMLX	= lib/MLX42
LIBFT	= libft
LIBPF	= ft_printf
LIBGN	= get_next_line

CFLAGS := -Wextra -Wall -Werror -Ofast
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(LIBPF) -I $(LIBGN)
LIBS = -Llibft -lft -Lft_printf -lftprintf -L${LIBMLX}/build -lmlx42 -lglfw -Lget_next_line -lget_next_line
SRCS := $(shell find ./src -iname "*.c")
OBJS := ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(HEADERS) $(LIBS) && printf "Created: %s\n" $(NAME)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(LIBMLX)/build

re: fclean all

.PHONY: all bonus clean fclean re libmlx
