# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 21:20:41 by rmander           #+#    #+#              #
#    Updated: 2021/06/18 21:32:27 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = ~/.brew/Cellar/llvm/12.0.0_1/bin/clang-12
INCLUDE = ./include
CFLAGS = -Wall -Wextra -Werror -MMD -I$(INCLUDE)
SRCS = ./src/pipex.c ./src/error.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
