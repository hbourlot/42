# Colors and formatting
RED	=				\033[1;31m
YELLOW = 			\033[1;33m
ORANGE = 			\033[1;38;5;214m
GREEN = 			\033[1;32m
GREEN_D = 			\033[3;32m
CYAN = 				\033[1;36m
RESET =				\033[0m
# --- END --

# Variables
CC = 				cc
CFLAGS = 			-Wall -Wextra -Werror -g
SRC_DIR = 			src/
SRC_DIR_B = 		bonus/
OBJ_DIR = 			OBJ/
INCLUDE = 			inc/
LIBFT_DIR = 		libraries/libft_upd/
LIBFT_LIB = 		$(LIBFT_DIR)libft.a
NAME = 				pipex
NAME_BONUS = 		pipex_bonus
PIPEX_LIB = 		libpipex.a
HEADER_FILE =		$(INCLUDE)lib_pipex.h
LINK = 				-L$(LIBFT_DIR) -lft
TOTAL_FILES = 		$(words $(SRC_FILES))
OS = 				$(shell uname)
COMPILED_FILES = 	0
LEAK = 				valgrind --leak-check=full --show-leak-kinds=all
LEAK_FULL =			valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes
MSG_MAC = 			"\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling... $<... $(RESET)"
MSG_LINUX = 		"\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling... $<... $(RESET)"
# --- END --

C_FUNCTIONS = 		args close command path pipex utils error parsing
SRC_FILES = 		$(addprefix $(SRC_DIR), $(C_FUNCTIONS:=.c))
OBJ_SOURCE =		$(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))
C_FUNCTIONS_B = 	args_bonus close_bonus command_bonus heredoc_bonus path_bonus pipex_bonus utils_bonus initialize_fd_bonus parsing_bonus
# C_FUNCTIONS_B = 	command here_doc pipex
SRC_FILES_B = 		$(addprefix $(SRC_DIR_B), $(C_FUNCTIONS_B:=.c))
OBJ_SOURCE_B =		$(addprefix $(OBJ_DIR), $(SRC_FILES_B:%.c=%.o))

all:				main.o $(NAME)

$(NAME): 			$(LIBFT_LIB) $(PIPEX_LIB) main.o
					@$(CC) main.o $(PIPEX_LIB) $(LINK) -I$(INCLUDE) -o $(NAME)
					@rm -rf $(OBJ_SOURCE_B)
					@echo "$(GREEN_D)executable '$(NAME)' created succesfully!$(RESET)"

$(PIPEX_LIB):		$(OBJ_SOURCE)
					@ar -rcs $@ $^
					@echo "$(CYAN)library created succesfully!$(RESET)"

$(OBJ_DIR)%.o: 		%.c $(HEADER_FILE)
					@mkdir -p $(dir $@)
					$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
					@printf $(MSG_MAC)
else
					@echo -n $(MSG_LINUX)
endif
					@$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

$(LIBFT_LIB):
					@make -s -C $(LIBFT_DIR)

main.o:				main.c
					@$(CC) -c $< -I$(INCLUDE) -o $@

clean:
					@printf "$(CYAN)Cleaning up *.o files...$(RESET)\b"
					@make clean -s -C $(LIBFT_DIR) > /dev/null
					@rm -rf main.o
					@rm -rf main_bonus.o
					@rm -rf $(OBJ_DIR)
					@echo " $(GREEN)Cleaned successfully.$(RESET)"

fclean:				clean
					@printf "$(CYAN)Cleaning up '$(NAME)' and *.a files...$(RESET)\b"
					@make fclean -s -C $(LIBFT_DIR) > /dev/null
					@rm -rf $(PIPEX_LIB)
					@rm -rf $(NAME)
					@echo " $(GREEN)Cleaned successfully.$(RESET)"

re: 				fclean all

TOTAL_FILES = 		$(words $(OBJ_SOURCE_B) $(OBJ_SOURCE))


bonus: 				do_bonus

compile:			$(OBJ_SOURCE_B) $(LIBFT_LIB) main.o
					@$(CC) main.o $(OBJ_SOURCE_B) $(LINK) -I$(INCLUDE) -o $(NAME)
					@echo "$(GREEN_D)executable bonus '$(NAME)' created successfully!$(RESET)"
				
do_bonus:
					@if [ -d ./OBJ/BONUS ] && [ $$(ls $(OBJ_SOURCE_B) 2>/dev/null | wc -l) -eq $$(echo $(OBJ_SOURCE_B) | wc -w) ]; then \
					rm -rf $(PIPEX_LIB); \
					echo "make: Nothing to be done for 'bonus'."; \
					else \
					rm -rf $(PIPEX_LIB); \
					make -s compile; \
					fi

run:
	@make -s && ./pipex infile "cat -e" ls outfile

val:
	@make -s && $(LEAK) ./pipex here_doc EOF ls "grep pipex" outfile

valfull:
	@make bonus -s && $(LEAK_FULL) ./pipex here_doc EOF ls "grep pipex" outfile