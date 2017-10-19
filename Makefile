# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/19 15:00:55 by lgaveria          #+#    #+#              #
#    Updated: 2017/10/19 19:02:52 by lgaveria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lgaveria.filler

SRCS = cleanup_functions.c \
		filler.c \
		ft_itoa.c \
		get_context.c \
		get_valid_position.c \
		lib_functions.c \
		lib_functions2.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \

SRC = $(addprefix srcs/, $(SRCS))

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		gcc $^ -o $@

%.o: %.c
		gcc -c $^ -o $@ $(CFLAGS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
