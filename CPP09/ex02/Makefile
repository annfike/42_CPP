NAME = PmergeMe

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98
#CFLAGS = -Wall -Werror -Wextra -std=c++11

SRCS = main.cpp PmergeMe.cpp

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

.PHONY: all clean fclean re

