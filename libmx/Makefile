CC = clang
CFLAGS = -std=c99 -Wall -Wextra -Werror

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(addprefix $(OBJ_DIR)/,$(notdir $(SOURCES:.c=.o)))
HEADERS = $(wildcard $(INC_DIR)/*.h)

EXECUTABLE = libmx.a

all: install

install: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@ar rcs $@ $^
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
	@printf "\r\33[2K$(EXECUTABLE)\t   \033[33;1mcompile \033[0m$(notdir $<) "

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(OBJ_DIR)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@rm -f $(EXECUTABLE)
	@printf "$(EXECUTABLE)\t   \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install

start: $(SOURCES)
	$(CC) $(CFLAGS) $^ -o a.out && ./a.out
