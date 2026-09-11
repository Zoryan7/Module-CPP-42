CC= c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

CFILES = megaphone.cpp

OFILES = $(CFILES:.cpp=.o)

NAME = megaphone

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