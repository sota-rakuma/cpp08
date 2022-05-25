CXX:=c++
CXXFLAGS:=-std=c++98 -Wall -Wextra -Werror
DEBUGFLAGS:=-g -fsanitize=address -fsanitize=leak -fsanitize=undefined
NAME:=a.out
SRC:=main.cpp \
	easyfind.cpp
OBJ_DIR:=obj
OBJ:=$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
DEP_DIR:=dep
DEP:=$(addprefix $(DEP_DIR)/, $(SRC:.cpp=.d))

all: $(NAME)

ifdef DEBUG
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -o $(NAME) $(OBJ)
else
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
endif

$(OBJ_DIR)/%.o: %.cpp
	@if ! [ -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi
	@ if ! [ -d $(DEP_DIR) ]; then \
		mkdir -p $(DEP_DIR); \
	fi
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<
	@mv $(OBJ_DIR)/*.d $(DEP_DIR)/

clean:
	rm -fR $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re