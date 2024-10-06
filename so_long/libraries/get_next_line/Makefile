CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = libget_next_line.a
INC = inc/
OBJ_DIR = OBJ/
TOTAL_FILES = $(words $(OBJ_F))
COMPILED_FILES = 0
OS = $(shell uname)

C_FUNCTIONS = get_next_line.c get_next_line_utils.c \
              get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ_F = $(C_FUNCTIONS:%.c=%.o)
OBJ_SRC = $(addprefix $(OBJ_DIR), $(OBJ_F))

# Colors and formatting
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

all: $(LIB)

$(LIB): $(OBJ_SRC)
	ar rcs $@ $^
	@echo "$(CYAN)library created succesfully!$(RESET)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
	@echo -n "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))% ] $(ORANGE)Compiling $<... $(RESET)" && \
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
	@printf "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))%% ] $(ORANGE)Compiling $<... $(RESET)"
else
	@echo -n "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))% ] $(ORANGE)Compiling $<... $(RESET)"
endif
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)
clean:
	@rm -rf $(OBJ_DIR) *.o

fclean: clean
	@rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re