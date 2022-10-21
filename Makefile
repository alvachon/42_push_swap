# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:49:39 by alvachon          #+#    #+#              #
#    Updated: 2022/10/21 16:46:04 by alvachon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define SANDWICH
                     _                                   
                    | |                                  
  _ __   _   _  ___ | |__    ___ __      __ __ _  _ __   
 | '_ \ | | | |/ __|| '_ \  / __|\ \ /\ / // _` || '_ \  
 | |_) || |_| |\__ \| | | | \__ \ \ V  V /| (_| || |_) | 
 | .__/  \__,_||___/|_| |_| |___/  \_/\_/  \__,_|| .__/  
 | |                    ______                   | |     
 |_|                   |______|                  |_|     
                         _            _        _         
                        | |          (_)      | |        
  ___   __ _  _ __    __| |__      __ _   ___ | |__      
 / __| / _` || '_ \  / _` |\ \ /\ / /| | / __|| '_ \     
 \__ \| (_| || | | || (_| | \ V  V / | || (__ | | | |    
 |___/ \__,_||_| |_| \__,_|  \_/\_/  |_| \___||_| |_|    
                                                         
endef
export SANDWICH

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
CC = gcc

DIR = srcs

SRCS_DIR =  srcs/arg_split.c \
			srcs/error_handling.c \
			srcs/error_helper.c \
			srcs/error_return.c \
			srcs/get_stack.c \
			srcs/index_solver.c \
			srcs/moves.c \
			srcs/push_checker.c \
			srcs/push_swap.c \
			srcs/stack_action.c \
			srcs/stack_finder.c \
			srcs/type_algo.c \
			srcs/type_sandwich.c \
			srcs/utilities.c \

SRC =	arg_split.c \
		error_handling.c \
		error_helper.c \
		error_return.c \
		get_stack.c \
		index_solver.c \
		moves.c \
		push_checker.c \
		push_swap.c \
		stack_action.c \
		stack_finder.c \
		type_algo.c \
		type_sandwich.c \
		utilities.c \

OBJ_DIR = _objFiles
OBJ_S = $(SRC:.c=.o)
OBJS = $(OBJ_DIR)/*.o

HEAD = include/push_swap.h

# LIBRARY
LISTDC_A = doubly_circ_ll.a
LISTDC_DIR = doubly_circ_ll
LISTDC = $(LISTDC_DIR)/$(LISTDC_A)

# COLORS
YELL= '\033[0;33m'
GRE= '\033[0;32m'
RED = '\[\033[0;31m\]'
GRAY='\033[2;37m'
NONE= '\033[0m'

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	@clear
	@echo "$$SANDWICH"
	@echo $(YELL) "\nIncoming :\n" $(NONE)
	@make -C $(LISTDC_DIR)
	@$(CC) $(FLAGS) $(LISTDC) $(OBJ_S) -o $(NAME)
	@mv $(OBJ_S) $(OBJ_DIR)
	@echo $(GRE) "\nCompilation all done.\n" $(NONE)

$(OBJS): $(SRCS_DIR)
	@echo $(GRAY) "Making Object Files" $(NONE)
	@gcc $(FLAGS) -c $(SRCS_DIR)
	@echo $(GRAY) "Moving Object Files to $(OBJ_DIR). . ." $(NONE)
	@mkdir -p $(OBJ_DIR)

clean:
	@echo $(YELL) "\nRemoving object:\n" $(NONE)
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LISTDC_DIR) clean
	@echo $(NONE)$(GRE) "OK - - - - - - - - - - \n" $(NONE)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LISTDC_DIR) fclean
	@echo $(NONE)$(GRE) "OK - - - - - - - - - - \n" $(NONE)

re: fclean all

valgrind:
	@valgrind --leak-check=full ./push_swap 2 1
	@valgrind --leak-check=full ./push_swap 2 3 1
