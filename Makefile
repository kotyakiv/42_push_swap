# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 12:48:14 by ykot              #+#    #+#              #
#    Updated: 2022/06/16 15:32:37 by ykot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = reading.c commands.c checker.c dispatcher.c printing.c stack_b.c stack_a.c
SRC2 = reading.c commands.c dispatcher.c push_swap.c printing.c finding.c sortinga.c \
stack_b.c stack_a.c
OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)
CFLAGS = -c -Wall -Werror -Wextra
NAME = checker

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(SRC)
	@gcc -o $(NAME) $(OBJ) -L. -lft

g:
	@gcc -g -o a $(SRC) libftprintf/*.c libftprintf/ft_printf/*.c

gp:
	@gcc -g -o a $(SRC2) libftprintf/*.c libftprintf/ft_printf/*.c
	
p:
	@gcc $(CFLAGS) $(SRC2)
	@gcc -o push_swap $(OBJ2) -L. -lft

clean:
	@rm -rf $(OBJ)

cleanp:
	@rm -rf $(OBJ2)
	
fclean: clean
	@rm -rf $(NAME)

fcleanp: cleanp
	@rm -rf push_swap

	
re: fclean all

rep: fcleanp p