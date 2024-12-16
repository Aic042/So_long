# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 13:57:24 by root              #+#    #+#              #
#    Updated: 2024/12/15 14:16:43 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

CLR_RMV   := \033[0m
RED       := \033[1;31m
GREEN   := \033[1;32m
YELLOW    := \033[1;33m
BLUE    := \033[1;34m
CYAN    := \033[1;36m
define  ART
$(BLUE)
                     █
                    ███
                    ███
                   █████
                  ██████
                  ███████
                 █████████
   █████████████████████████████████████
     █████████████████████████████████
       █████████████████████████████
          ███████████████████████
            ███████████████████
              ███████████████
             █████████████████
            ███████████████████
            ████████  █████████
           ███████       ███████
           ████             ████
          ███                 ███
      ___           ___           ___
     /\  \         /\  \         /\  \
    /::\  \       /::\  \       /::\  \
   /:/\:\  \     /:/\:\  \     /:/\:\  \
  /:/  \:\  \   /::\~\:\  \   /::\~\:\  \
 /:/__/ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\
 \:\  \  \/__/ \/__\:\/:/  / \/__\:\/:/  /
  \:\  \            \::/  /       \::/  /
   \:\  \            \/__/         \/__/
    \:\__\
     \/__/
 $(CLR_RMV)
endef
export  ART

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx