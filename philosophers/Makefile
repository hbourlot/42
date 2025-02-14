# Colors and formatting
RED				=\033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC				= cc
CFLAGS			= -Wall -Wextra -Werror #-fsanitize=thread -g -pthread
LIB				= libphilo.a
INCLUDE 		= inc/
HEADER_FILE		= $(INCLUDE)philosophers.h
SRC_DIR 		= sources/
BONUS_DIR 		= bonus/
OBJ_DIR 		= objects/
TOTAL_FILES		= $(words $(OBJS_SRC))
COMPILED_FILES	= 0
OS				= $(shell uname)
MSG_MAC 		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling... $<... $(RESET)"
MSG_LINUX 		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling... $<... $(RESET)"
NAME			= philo
MAIN_FUNCTION	= main.c
M_FUNCTIONS 	= initialize parsing routine monitor philos time utils free eating thread_utils
VALGRIND		= valgrind --tool=helgrind -s
SRC_FILES 		= $(addprefix $(SRC_DIR), $(M_FUNCTIONS:=.c))
OBJS_SRC 		= $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o))

.PHONY: 		all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(LIB) main.o $(HEADER_FILE)
				@$(CC) $(CFLAGS) main.o -L./ -lphilo -o $@
				@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET) ✅"

$(LIB):			$(OBJS_SRC) 
				@ar rcs $@ $(OBJS_SRC)
				@echo "$(CYAN)library created successfully!$(RESET)"

$(OBJ_DIR)%.o:	%.c $(INCLUDE)
				@mkdir -p $(dir $@)
				$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
				@printf $(MSG_MAC)
else
				@echo -n $(MSG_LINUX)
endif
				@$(CC) $(CFLAGS) -c $< -I./$(INCLUDE) -o $@

main.o:			main.c $(INCLUDE)
				@$(CC) -c main.c $(CFLAGS) -I./$(INCLUDE) -o $@

clean:
				@printf "$(CYAN)Cleaning up *.o files...$(RESET)\b"
				@rm -rf $(OBJ_DIR)
				@rm -rf main.o
				@echo " $(GREEN)Cleaned successfully.$(RESET) ✅"

fclean: 		clean
				@printf "$(CYAN)Cleaning up '$(NAME)' and *.a files...$(RESET)\b"
				@rm -f $(LIB)
				@rm -rf	$(NAME)
				@echo " $(GREEN)Cleaned successfully.$(RESET) ✅"

re: 			fclean all
