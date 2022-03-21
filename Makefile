# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 12:48:14 by ykot              #+#    #+#              #
#    Updated: 2022/03/20 22:28:10 by ykot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = reading.c commands.c main.c dispatcher.c checking.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Werror -Wextra
NAME = checker

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(SRC)
	@gcc -o $(NAME) $(OBJ) -L. -lft

g:
	@gcc -g -o a *.c libftprintf/*.c libftprintf/ft_printf/*.c
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all