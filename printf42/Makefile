# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 21:48:30 by maeskhai          #+#    #+#              #
#    Updated: 2024/11/30 11:03:33 by maeskhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c ft_putnbr.c ft_putnbr_u.c ft_putstr.c ft_putadd.c ft_puthexa.c  ft_printf.c 
OBJ = ${SRC:.c=.o}
NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean:
	rm -rf ${NAME} ${OBJ}

re: fclean all