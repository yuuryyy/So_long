# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychagri <ychagri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 23:23:35 by ychagri           #+#    #+#              #
#    Updated: 2024/06/28 13:25:23 by ychagri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long

NAME_B := so_long_b

CC		:= cc

CFLAGS	:= -g  -Wall -Wextra -Werror 

LIBRARY	:= lib/libft.a

HEADERS	:= Mandatory/Inc/so_long.h

HEADERS_B := bonus/so_long_bonus.h

SRCS_G	:=  Mandatory/parse/check_extension.c \
		   Mandatory/parse/get_filename.c \
		   Mandatory/parse/check_map.c \
		   Mandatory/parse/check_chars.c \
		   Mandatory/tools/free_arr.c \

SRCS	:= Mandatory/main.c \
		   Mandatory/parse/check_elements.c \
		   Mandatory/parse/error_check.c \
		   Mandatory/tools/movements.c \

SRCS_B	:= bonus/main.c \
			bonus/init_data.c \
			bonus/parse.c \
			bonus/error.c \

OBGS_G	:= $(SRCS_G:.c=.o)

OBGS	:= $(SRCS:.c=.o)

OBGS_B	:= $(SRCS_B:.c=.o)

all:	$(NAME)

lib:
	make -C lib

$(NAME): $(OBGS) $(OBGS_G) lib
	$(CC)  -lmlx -framework OpenGL -framework AppKit  $(CFLAGS) $(LIBRARY) $(OBGS) $(OBGS_G) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B): $(OBGS_B)  $(OBGS_G) lib
	$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(LIBRARY) $(OBGS_B)  $(OBGS_G) -o $(NAME_B)

%.o: %.c $(HEADERS_B) $(HEADERS)
		$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	make clean -C lib
	rm -rf $(OBGS)
	rm -rf $(OBGS_G)
	rm -rf $(OBGS_B)
	

fclean:	clean
	make fclean -C lib
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

push:	fclean
	git add .
	git commit -m "so_long updates"
	git push

.PHONY: clean fclean re lib bonus
