# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youssra <youssra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 01:10:21 by ychagri           #+#    #+#              #
#    Updated: 2024/06/19 16:08:49 by youssra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror

ARC = ar rc

LIBRARY = libft.h

LIBRARY_P = Ft_printf/ft_printf.h

LIBRARY_G = Get_next_line/get_next_line.h

SRC = Libft/ft_isdigit.c Libft/ft_memset.c  Libft/ft_isprint.c Libft/ft_split.c Libft/ft_itoa.c Libft/ft_strmapi.c \
		Libft/ft_bzero.c   Libft/ft_atoi.c Libft/ft_strncmp.c Libft/ft_memchr.c Libft/ft_putstr_fd.c Libft/ft_striteri.c \
		Libft/ft_tolower.c  Libft/ft_strlen.c  Libft/ft_strlcat.c Libft/ft_calloc.c Libft/ft_putnbr_fd.c  \
		Libft/ft_toupper.c Libft/ft_isalnum.c Libft/ft_strrchr.c  Libft/ft_strlcpy.c Libft/ft_memcmp.c Libft/ft_putendl_fd.c \
		Libft/ft_isalpha.c Libft/ft_memcpy.c Libft/ft_strchr.c   Libft/ft_strnstr.c Libft/ft_strjoin.c Libft/ft_strtrim.c  \
		Libft/ft_isascii.c Libft/ft_memmove.c Libft/ft_isascii.c Libft/ft_strchr.c Libft/ft_strdup.c Libft/ft_substr.c Libft/ft_putchar_fd.c \
		Libft/ft_lstnew.c  Libft/ft_lstadd_front.c Libft/ft_lstadd_back.c Libft/ft_lstsize.c Libft/ft_lstlast.c Libft/ft_lstdelone.c \
		Libft/ft_lstclear.c Libft/ft_lstiter.c Libft/ft_lstmap.c\

SRC_P = Ft_printf/ft_putchar.c \
		Ft_printf/ft_putnbr.c \
		Ft_printf/ft_putstr.c \
		Ft_printf/ft_hex.c \
		Ft_printf/ft_printf.c \
		Ft_printf/ft_putadd.c Ft_printf/u.c \

SRC_G =Get_next_line/get_next_line.c \
		Get_next_line/get_next_line_utils.c \
		
OBJS = $(SRC:.c=.o)

OBJS_P = $(SRC_P:.c=.o)

OBJS_G = $(SRC_G:.c=.o)


all:$(NAME)

$(NAME): $(OBJS) $(OBJS_P) $(OBJS_G)
	$(ARC) $(NAME) $(OBJS) $(OBJS_P) $(OBJS_G)
	
%.o : %.c	$(LIBRARY) $(LIBRARY_G) $(LIBRARY_P)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_G)
	rm -f $(OBJS_P)


fclean: clean
	rm -f $(NAME)

re : fclean all 

.PHONY: clean all re fclean
