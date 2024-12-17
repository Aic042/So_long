# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 11:03:04 by aingunza          #+#    #+#              #
#    Updated: 2024/10/22 11:03:05 by aingunza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc
LIBC = ar rc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c ft_printf.c ft_putunsigned.c ft_ptrhandler.c
OBGS = $(SRCS:.c=.o)

all:${NAME}

${NAME}:${OBGS}
	${LIBC} ${NAME} ${OBGS}
clean:
	rm -f ${OBGS}
fclean:clean
	rm -f ${NAME}
re:fclean all