CXX:=c++
CXXFLAGS:=-std=c++98 -Wall -Wextra -Werror
DEBUGFLAGS:=-g -fsanitize=address -fsanitize=leak -fsanitize=undefined
NAME:=a.out
SRC:=Span.cpp\
	main.cpp
#OBJ=$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR:=obj
ifdef TEST
CXXFLAGS+=-DTEST
endif
DEP_DIR:=dep
OBJ:=$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEP:=$(addprefix $(DEP_DIR)/, $(SRC:.cpp=.d))

all: $(NAME)

ifdef DEBUG
$(NAME): $(OBJ_DIR) $(DEP_DIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -o $(NAME) $(OBJ)
else
$(NAME): $(OBJ_DIR) $(DEP_DIR) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
endif

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR);

$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<
	@mv $(OBJ_DIR)/*.d $(DEP_DIR)/

clean:
	rm -fR $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re