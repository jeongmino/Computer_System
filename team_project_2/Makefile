CXX			=	c++
# CXXFLAGS	=	-Wall -Wextra -Werror
RM			=	rm -rf

OBJS_DIR	:=	objs/
DEPS_DIR	:=	deps/

SRCS		:=	$(wildcard src/*.cpp)
OBJS		:=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEPS		:=	$(addprefix $(DEPS_DIR), $(SRCS:.cpp=.d))
NAME		:=	Cash

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJS_DIR)%.o : %.cpp
	@mkdir -p $(dir $@)
	@mkdir -p $(DEPS_DIR)
	$(CXX) $(CXXFLAGS) $< -c -o $@ -MMD
	mv $(@:.o=.d) $(DEPS_DIR)

clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(DEPS_DIR)

fclean: clean
	$(RM) $(NAME)

re: | fclean all

.PHONY: all clean fclean re