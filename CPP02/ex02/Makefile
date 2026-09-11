CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

CDIR = srcs
ODIR = includes/obj

CFILES = main.cpp Fixed.cpp

SOURCES = $(addprefix $(CDIR)/, $(CFILES))
OFILES = $(SOURCES:$(CDIR)/%.cpp=$(ODIR)/%.o)

NAME = Orthodox

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

$(ODIR)/%.o: $(CDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
