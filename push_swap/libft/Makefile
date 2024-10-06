CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a

LIB_DIR = inc/
S_DIR = SRC/
B_DIR = BONUS/
OBJ_DIR = OBJ/

#SCRIPT FILE
MAIN_SRC=main.c

CFUNCTIONS=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
			ft_memchr ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup ft_strlcpy ft_strlen \
			ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_strjoin ft_strtrim \
			ft_substr ft_split ft_striteri ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_strmapi \
			ft_itoa ft_memcmp ft_putstr_fd ft_strlcat \
			ft_itoa_iter ft_linelen ft_nbrlen ft_strcmp \


BONUS=	ft_lstnew ft_lstadd_front ft_lstsize ft_lstadd_back ft_lstmap ft_lstiter ft_lstlast \
		ft_lstdelone ft_lstclear \

#Source and Object files
SRC_FILES = $(addprefix $(S_DIR), $(CFUNCTIONS:=.c))
B_FILES = $(addprefix $(B_DIR), $(BONUS:=.c))

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:%.c=%.o)) 
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(B_FILES:%.c=%.o))

#Targets that doesn't take into consideration for execution that matches its name.
.PHONY: all clean fclean re bonus

all: $(NAME)
	

$(NAME): $(OBJS) $(OBJS_BONUS)
	ar rcs $@ $^

bonus: $(OBJS) $(OBJS_BONUS)
	@make functions="$(OBJS_BONUS) all" | sed '2!d'
	@ar rcs $(NAME) $^

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -I./$(LIB_DIR) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: clean fclean show_ascii all bonus
