# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmouaike <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:55:03 by jmouaike          #+#    #+#              #
#    Updated: 2023/03/14 10:55:10 by jmouaike         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= a.out
SRC_FILES	= main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp
SRC_DIR		= ./src/
INC_DIR		= ./inc/
OBJ_DIR		= ./obj/

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))

CXX			= c++
CXXFLAGS	= -std=c++98
CFLAGS		= -Wall -Werror -Wextra

COL_RED = @echo -n "\e[1;31m"
COL_GRN = @echo -n "\e[1;32m"
COL_YEL = @echo -n "\e[1;33m"
COL_BLU = @echo -n "\e[1;34m"
COL_PUR = @echo -n "\e[1;35m"
COL_RESET = @echo -n "\e[0;32m"

all: $(NAME)

$(NAME): $(OBJ)
	$(COL_YEL)
	$(CXX) $(CXXFLAGS) $(CFLAGS) $(OBJ) -o $(NAME)
	$(COL_GRN)
	@echo  $(NAME) " executable is ready !"
	$(COL_RESET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(COL_BLU)
	$(CXX) $(CXXFLAGS) $(CFLAGS) -I$(INC_DIR) -c $< -o $@ 
	$(COL_RESET)

clean: $(OBJ_DIR)
	$(COL_RED)
	@rm -rfv $(OBJ)
	rmdir $(OBJ_DIR)
	$(COL_RESET)

fclean: clean
	$(COL_PUR)
	@rm -rfv $(NAME)
	$(COL_RESET)

re: fclean all

run: $(NAME)
	@./$(NAME)

.PHONY : run re fclean clean
