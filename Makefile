# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 23:23:35 by ychagri           #+#    #+#              #
#    Updated: 2024/03/13 06:11:30 by ychagri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long

CC		:= cc

CFLAGS	:= -g -Wall -Wextra -Werror -fsanitize=address

LIBRARY	:= lib/libft.a

HEADERS	:= Mandatory/Inc/so_long.h

SRCS	:= Mandatory/main.c \
		   Mandatory/parse/check_extension.c \
		   Mandatory/parse/get_filename.c \
		   Mandatory/parse/check_map.c \
		   Mandatory/parse/check_elements.c \
		   Mandatory/parse/check_chars.c \
		   
OBGS	:= $(SRCS:.c=.o)

all:	$(NAME)

lib:
	make -C lib

$(NAME): $(OBGS) lib
	$(CC) $(CFLAGS) $(LIBRARY) $(OBGS) -o $(NAME)

%.o: %.c	Mandatory/Inc/so_long.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C lib
	rm -rf $(OBGS)

fclean:	clean
	make fclean -C lib
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re lib
