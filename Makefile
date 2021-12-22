# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 18:31:42 by fel-maac          #+#    #+#              #
#    Updated: 2021/11/21 11:52:38 by fel-maac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC	= ft_printf.c

UTILS = utils/ft_putchar.c utils/ft_putstr.c utils/ft_putnbr.c utils/ft_putnbr_unsigned.c utils/ft_putnbr_address.c utils/ft_putnbr_hex.c

OBJ	= $(UTILS:.c=.o) $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME): $(OBJ)
	ar -rcs $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
