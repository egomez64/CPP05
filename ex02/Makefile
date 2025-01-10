NAME = aform

GXX = c++

CFLAGS = -Wall -Werror -Wextra -g --std=c++98

SRC = main.cpp \
		Bureaucrat.cpp \
		AForm.cpp

HEADER = Bureaucrat.hpp \
			AForm.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GXX) $(CFLAGS) $^ -o $@

%o: %cpp
	$(GXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
