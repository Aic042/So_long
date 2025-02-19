NAME	= so_long
LIBMLX	= lib/MLX42/build
LIBFT	= libft
LIBPF	= ft_printf
LIBGN	= get_next_line

CFLAGS := -Wextra -Wall -Werror -Ofast
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT) -I $(LIBPF) -I $(LIBGN)
LIBS = -lglfw -lftprintf -lft -lget_next_line ${LIBMLX}/libmlx42.a
SRCS := $(shell find ./src -iname "*.c")
#SRCS_BONUS := $(shell find ./src_bonus -iname "*.c")
OBJS := ${SRCS:.c=.o}
#OBJS_BONUS := ${SRCS_BONUS:.c=.o}

all: libmlx $(NAME)

#bonus: libmlx $(NAME_BONUS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: %s\n" $(notdir $<)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && printf "Created: %s\n" $(NAME)

#(NAME_BONUS): $(OBJS_BONUS)
#	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS) && printf "Created: %s\n" $(NAME_BONUS)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(LIBMLX)/build

re: fclean all

.PHONY: all bonus clean fclean re libmlx
