CC= c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

CFILES = Account.cpp tests.cpp

OFILES = $(CFILES:.cpp=.o)

NAME = Account

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re