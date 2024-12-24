NAME := cellularena

CC := c++
FILE_TYPE := cpp
CFLAGS := -Werror -Wall -Wextra -MMD -MP -g3 -gdwarf-4

SRC_PATH := src/
OBJ_PATH := obj/
INC_PATH := inc/

INC_FILES := $(INC_PATH)*
SRC_FILES := Cell Generator Map Stock growth main path
SRC := $(patsubst %,$(SRC_PATH)%.$(FILE_TYPE), $(SRC_FILES))
OBJ := $(patsubst %,$(OBJ_PATH)%.o,$(SRC_FILES))
DEP := $(OBJ:.o=.d)

BUNDLE_PATH := bundler
BUNDLED := $(BUNDLE_PATH)/bundled.cpp

all: $(NAME)

bundle: all
	cp -r $(SRC) $(INC_FILES) $(BUNDLE_PATH)
	python3 $(BUNDLE_PATH)/bundler.py -i $(BUNDLE_PATH)/main.cpp -o $(BUNDLED)

copy:
	xclip -selection clip < $(BUNDLED)

$(NAME): $(OBJ_PATH) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

-include $(DEP)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PATH)

clean:
	rm -rf $(OBJ_PATH)
	rm -f $(BUNDLE_PATH)/*pp

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re