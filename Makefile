# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youssra <youssra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 23:23:35 by ychagri           #+#    #+#              #
#    Updated: 2024/06/19 02:57:04 by youssra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long

CC		:= cc

CFLAGS	:= -g  -Wall -Wextra -Werror
#-fsanitize=address

MLX_FLAGS = -Lmlx  -L/usr/lib/X11 -lXext -lX11

INCLUDES = -I/usr/include -Imlx

LIBRARY	:= lib/libft.a

HEADERS	:= Mandatory/Inc/so_long.h

SRCS	:= Mandatory/main.c \
		   Mandatory/parse/check_extension.c \
		   Mandatory/parse/get_filename.c \
		   Mandatory/parse/check_map.c \
		   Mandatory/parse/check_elements.c \
		   Mandatory/parse/check_chars.c \
		   Mandatory/parse/error_check.c \
		   Mandatory/tools/free_arr.c
		   
OBGS	:= $(SRCS:.c=.o)

all:	$(NAME)

lib:
	make -C lib

$(NAME): $(OBGS) lib
	$(CC)  $(CFLAGS) $(MLX_FLAGS) $(OBGS) $(LIBRARY)  -o $(NAME)

%.o: %.c Mandatory/Inc/so_long.h
		$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	make clean -C lib
	rm -rf $(OBGS)

fclean:	clean
	make fclean -C lib
	rm -rf $(NAME)

re: fclean all

push:	fclean
	git add .
	git commit -m "so_long updates"
	git push

.PHONY: clean fclean re lib
