# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frchaban <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 18:24:04 by frchaban          #+#    #+#              #
#    Updated: 2020/03/31 21:10:04 by frchaban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -g -fsanitize=address -Wall -Wextra -Werror

SRCS = srcs/*.c

INCLUDES = -Iincludes


all : lib $(NAME)

lib :
			@make -C libft/ all 

$(NAME) :	
			@$(CC) $(SRCS)  $(FLAGS) $(INCLUDES) libft/libft.a

test :	
			@$(CC) $(SRCS) $(INCLUDES) libft/libft.a
clean :
			rm -f *.o

fclean : clean
			rm -f  $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
