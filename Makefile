# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 20:31:35 by wshee             #+#    #+#              #
#    Updated: 2025/01/14 16:22:45 by wshee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color
GREEN = \033[0;32m
WHITE = \033[0m

#Program Name
NAME = push_swap
BONUS_NAME = checker

#The -I (uppercase i) flag is used to add a directory to the list of directories
#the compiler searches for header files (#include directives).
#Directories
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = include/
SRC_DIR = src/
OPERATION_DIR = $(SRC_DIR)operation/
INC = -I$(INC_DIR)

CC = cc -g3 #-O0 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)

#Source Files
OPERATION_SRC = push.c	reverse_rotate.c	rotate.c	swap.c

#addprefix <prefix>, <list>
#<prefix> is the string that added to the beginning of each word
SRC = 	$(SRC_DIR)error_handling.c	$(SRC_DIR)init_stack.c	$(SRC_DIR)pre_sort.c	$(SRC_DIR)input.c\
		$(SRC_DIR)sort_big.c		$(SRC_DIR)sort_small.c	$(SRC_DIR)stack_utils.c \
		$(addprefix $(OPERATION_DIR)/, $(OPERATION_SRC))

PUSH_SWAP = $(SRC_DIR)push_swap.c

BONUS = $(SRC_DIR)checker.c

OBJ_SRC = $(SRC:.c=.o)
OBJ_PUSH_SWAP = $(PUSH_SWAP:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_SRC) $(OBJ_PUSH_SWAP)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ_SRC) $(OBJ_PUSH_SWAP) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)-----COMPILED DONE-----\n"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_SRC) $(OBJ_BONUS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ_SRC) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJ_SRC) $(OBJ_PUSH_SWAP) $(OBJ_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)-----FULLY REMOVED-----\n$(WHITE)"

re: fclean all

.PHONY: all clean fclean re bonus
