NAME	= so_long
LIBMLX	= lib/MLX42
LIBFT	= lib/libft

CFLAGS = -Wextra -Wall -Werror -Ofast -g
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS = -L$(LIBFT) -L$(LIBMLX)/build -lmlx42 -lglfw
SRCS := $(shell find ./src -iname "*.c")
OBJS := $(SRCS:.c=.o)

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.o: %.c
	cc $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	cc $(OBJS) -L$(LIBFT) -lft -L$(LIBMLX)/build -lmlx42 -lglfw -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)	
	@rm -rf $(LIBMLX)/build

re: fclean all

.PHONY: all bonus clean fclean re libmlx libft % 