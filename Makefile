# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 12:48:14 by ykot              #+#    #+#              #
#    Updated: 2022/06/30 17:11:46 by ykot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON =	commands.c \
				dispatcher.c \
				reading.c \
				subfunctions.c 

SRC_PUSH_SWAP = algorithm.c \
				stack_a.c \
				stack_b.c \
				quicksort_a.c \
				quicksort_b.c \
				first_stack_sort.c \
				first_quicksort_a.c \
				finding_pivot.c \
				push_swap.c

SRC_CHECKER =	checker.c \
				printing.c

OBJ_COMMON = $(SRC_COMMON:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
CFLAGS = -c -Wall -Werror -Wextra
NAME = checker
LIBFTPATH = libft/
COMMON_PATH = src/common/
CHECKER_PATH = src/checker/
PUSH_SWAP_PATH = src/push_swap/


all: $(NAME) push_swap

$(NAME):
	@make -C $(LIBFTPATH)
	@gcc $(CFLAGS) $(addprefix $(COMMON_PATH), $(SRC_COMMON)) \
	$(addprefix $(CHECKER_PATH), $(SRC_CHECKER)) -I includes/
	@gcc -o $(NAME) $(OBJ_COMMON) $(OBJ_CHECKER) -L $(LIBFTPATH) -lft

push_swap:
	@gcc $(CFLAGS) $(addprefix $(PUSH_SWAP_PATH), $(SRC_PUSH_SWAP)) -I includes/
	@gcc -o push_swap $(OBJ_COMMON) $(OBJ_PUSH_SWAP) -L $(LIBFTPATH) -lft

clean:
	@rm -rf $(OBJ_CHECKER) $(OBJ_COMMON) $(OBJ_PUSH_SWAP)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME) push_swap
	@make -C libft/ fclean

re: fclean all
