# Colors and formatting
RED=\033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

CC=cc
CFLAGS=-Wall -Wextra -Werror
LIB=libft.a

LIB_DIR = inc/
S_DIR = SRC/
B_DIR = BONUS/
OBJ_DIR = OBJ/
TOTAL_FILES = $(words $(OBJS) $(OBJS_BONUS))
COMPILED_FILES = 0
OS = $(shell uname)

#SCRIPT FILE
MAIN_SRC=main.c

CFUNCTIONS=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint	\
			ft_memchr ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup ft_strlcpy ft_strlen	\
			ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_strjoin ft_strtrim		\
			ft_substr ft_split ft_striteri ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_strmapi	\
			ft_itoa ft_memcmp ft_putstr_fd ft_strlcat 											\
			ft_itoa_iter ft_linelen ft_nbrlen ft_strcmp ft_lstduplicate ft_lstidx ft_lstvalue	\
			ft_free_split ft_strcpy ft_strcat											\


BONUS=	ft_lstnew ft_lstadd_front ft_lstsize ft_lstadd_back ft_lstmap ft_lstiter ft_lstlast 	\
		ft_lstdelone ft_lstclear																\

#Source and Object files
SRC_FILES = $(addprefix $(S_DIR), $(CFUNCTIONS:=.c))
B_FILES = $(addprefix $(B_DIR), $(BONUS:=.c))

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o)) 
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(B_FILES:%.c=%.o))

.PHONY: all clean fclean re bonus

all: $(LIB)
	
$(LIB): $(OBJS) $(OBJS_BONUS)
	@ar rcs $@ $^
	@echo "$(CYAN)library created succesfully!$(RESET)"

bonus: $(OBJS) $(OBJS_BONUS)
	@ar rcs $(LIB) $^

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
	@printf "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))%% ] $(ORANGE)Compiling $<... $(RESET)"
else
	@echo -n "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(( $(COMPILED_FILES) * 100 / $(TOTAL_FILES) ))% ] $(ORANGE)Compiling $<... $(RESET)"
endif
	@$(CC) $(CFLAGS) -c -I./$(LIB_DIR) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIB)

re: clean fclean all bonus