NAME	= so_long
LIBMLX	= lib/MLX42
LIBFT	= lib/libft
LIBPF	= lib/ft_printf
LIBGN	= lib/get_next_line

CFLAGS = -Wextra -Wall -Werror -Ofast -fPIE
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(LIBPF) -I $(LIBGN)
LIBS = -L$(LIBFT) -lft -L$(LIBPF) -lftprintf -L$(LIBMLX)/build -lmlx42 -lglfw -L$(LIBGN) -lget_next_line
SRCS := $(shell find ./src -iname "*.c")
OBJS := $(SRCS:.c=.o)

all: libmlx libft libftprintf libgnl $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

libftprintf:
	@make -C $(LIBPF)

libgnl:
	@make -C $(LIBGN)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(LIBS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)/build

re: fclean all

.PHONY: all bonus clean fclean re libmlx libft libftprintf libgnl