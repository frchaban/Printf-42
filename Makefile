# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 18:24:04 by frchaban          #+#    #+#              #
#    Updated: 2020/04/29 16:20:58 by frchaban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = ./srcs/

OBJS = $(SRCS:.c=.o)

SRCS:= $(filter-out ft_lst%.c, $(wildcard srcs/*.c))

INCLUDES = -I./includes

all:	lib $(NAME)

lib:
	@make -C libft/ all

$(NAME): $(OBJS)
	ar rcs $(NAME) $^ libft/*.o

$(OBJS) : $(HEADERS)

%.o: %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
			rm -f $(OBJS)
			@make -C libft/ clean

fclean: clean
			rm -f  $(NAME)
			@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus lib
