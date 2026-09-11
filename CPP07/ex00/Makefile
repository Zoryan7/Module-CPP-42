CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

CDIR = srcs
ODIR = includes/obj

CFILES = main.cpp 

SOURCES = $(addprefix $(CDIR)/, $(CFILES))
OFILES = $(SOURCES:$(CDIR)/%.cpp=$(ODIR)/%.o)

NAME = Whatever

all: $(NAME)

$(NAME): $(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES) -o $(NAME)

$(ODIR)/%.o: $(CDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I includes -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
