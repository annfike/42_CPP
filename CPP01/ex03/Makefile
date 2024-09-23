NAME = weapon

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = Weapon.cpp main.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

leaks: all
	leaks -atExit -- ./$(NAME)

.PHONY: all clean fclean re

