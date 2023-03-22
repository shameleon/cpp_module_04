NAME		= a.out
SRC			= main.cpp Base.cpp Derived1.cpp Derived2.cpp
OBJ			= $(SRC:.cpp=.o)

INC			= ./Diamond.hpp 
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
	$(COL_RESET)

%.o: %.cpp
	$(COL_BLU)
	$(CXX) $(CXXFLAGS) $(CFLAGS) -I $(INC)-c $< -o $@ 
	$(COL_RESET)

clean:
	$(COL_RED)
	@rm -rfv $(OBJ)
	$(COL_RESET)

fclean: clean
	$(COL_PUR)
	@rm -rfv $(NAME)
	$(COL_RESET)

re: fclean all

run: $(NAME)
	@./$(NAME)

.PHONY : run re fclean clean