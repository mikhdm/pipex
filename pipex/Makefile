# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmander <rmander@student.21-school.ru      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 19:21:05 by rmander           #+#    #+#              #
#    Updated: 2021/07/30 19:21:08 by rmander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = clang
INCLUDE = ./include
CFLAGS = -Wall -Wextra -Werror -MMD -I$(INCLUDE)
SRCS =  ./src/utils/ft_strlen_until.c \
		./src/utils/ft_strlen.c \
		./src/utils/ft_strdup_until.c \
		./src/utils/ft_splitf.c \
		./src/utils/ft_putendl_fd.c \
		./src/utils/ft_putstr_fd.c \
		./src/utils/ft_memcpy.c \
		./src/utils/ft_memset.c \
		./src/utils/ft_strjoin.c \
		./src/utils/ft_strcmp.c \
		./src/utils/ft_strchr.c \
		./src/utils/alloca_to.c \
		./src/utils/cleanup.c \
		./src/utils/getbin.c \
		./src/utils/child_by_index.c \
		./src/utils/ft_isspace.c \
		./src/utils/ft_split.c \
		./src/utils/ft_lstadd_back.c \
		./src/utils/ft_lstclear.c \
		./src/utils/ft_lstdelone.c \
		./src/utils/ft_lstnew.c \
		./src/environ.c \
		./src/pipex.c \
		./src/error.c \
		./src/main.c

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
