NAME=ex00

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS=main.cpp

OBJDIR=objs

OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))


ifeq ($(MAKECMDGOALS), debug)
	CXXFLAGS += -g -fsanitize=address
endif

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean:clean
	rm -rf $(NAME)

re:fclean
	make all

debug: re

.PHONY:		clean fclean all re debug
