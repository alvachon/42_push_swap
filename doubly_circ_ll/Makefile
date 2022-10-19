# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:48:39 by alvachon          #+#    #+#              #
#    Updated: 2022/10/19 17:54:35 by alvachon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doubly_circ_ll.a
FLAGS = -Wall -Wextra -Werror

SRC = $(CREATEDCLL_C)
OBJ_DIR = _objFiles
OBJ = creating_nodes.o

HEAD = include/doubly_circ_ll.h

CREATEDCLL_C = srcs/creating_nodes.c

# COLORS
NONE='\033[0m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
YELL= '\033[0;33m'

# RULES
all : $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY)"      - Generating $(NAME)"$(NONE)
	@ar rc $(NAME) $(OBJ_DIR)/$(OBJ)

$(OBJ): $(SRC)
	@gcc -g $(FLAGS) -c $(SRC)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)

clean:
	@echo $(NONE)$(GRAY) "Writing :" $(NONE)
	@echo $(CURSIVE) "     - Cleaning ..." $(NONE)
	@rm -f $(OBJ) $(OBJ_DIR)/$(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(NONE)$(GRAY) "Writing :" $(NONE)
	@echo $(CURSIVE) "     - Removing ..." $(NONE)
	@rm -f $(NAME)

re: fclean all

norm:
	@echo $(NONE)$(GRAY) "Writing :" $(NONE)
	@norminette $(SRC) $(HEAD)
	@echo ""$(NONE)