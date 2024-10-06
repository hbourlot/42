CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
#EXEC. FILE
TARGET=exec

#SCRIPT FILE
MAIN_SRC=main.c

CFUNCTIONS=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
			ft_memchr ft_memcpy ft_memmove ft_memset ft_strchr ft_strdup ft_strlcpy ft_strlen \
			ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper ft_strjoin ft_strtrim \
			ft_substr ft_split ft_striteri ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_strmapi \
			ft_itoa ft_memcmp ft_putstr_fd ft_strlcat


BONUS=	ft_lstnew ft_lstadd_front ft_lstsize ft_lstadd_back ft_lstmap ft_lstiter ft_lstlast \
		ft_lstdelone ft_lstclear

#Source and Object files
SRC_FILES=$(CFUNCTIONS:%=%.c)
OBJ_FILES=$(CFUNCTIONS:=.o)
OBJ_BONUS=$(BONUS:=.o)
# OBJ_FILES=$(patsubst %,%.o,$(CFUNCTIONS))

#Targets that doesn't take into consideration for execution that matches its name.
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

bonus: $(OBJ_BONUS) libft.h
	ar rcs $(NAME) $^

$(OBJ_BONUS) : %.o:%.c
	$(CC) -c $< $(CFLAGS) -I. -o $@

$(OBJ_FILES) : %.o:%.c
	$(CC) $(CFLAGS) -c $< -I. -o $@
clean:
	@echo "Removed '/obj' archive!"
	@rm -rf $(OBJ_FILES) $(OBJ_BONUS)

fclean: clean
	@echo "Removed $(NAME) and $(OBJ_FILES)!"
	@rm -f $(NAME) $(OBJ_FILES)

re: clean fclean all bonus

