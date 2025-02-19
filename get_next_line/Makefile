# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 14:05:02 by erigolon          #+#    #+#              #
#    Updated: 2025/02/18 22:53:39 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

LIB = ar rcs

SRC = get_next_line.c \
	get_next_line_utils.c

OBJ = ${SRC:.c=.o}

RM = rm -f

cc = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re