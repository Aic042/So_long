# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  #+#    #+#              #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 10:19:03 by erigolon          #+#    #+#              #
#    Updated: 2025/02/18 22:56:11 by root             ###   ########.fr        #
#                                                                              #

NAME = libftprintf.a

LIB = ar rcs

SRCS = ft_printf.c ft_ptrhandler.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putstr.c ft_putunsigned.c

OBJ = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

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
