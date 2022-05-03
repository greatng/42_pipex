NAME 	=	libft.a

SOURCE 	=	ft_atoi.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		 	ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strncmp.c \
		 	ft_strlcpy.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_memchr.c \
			ft_memcmp.c ft_memmove.c ft_calloc.c ft_strdup.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_striteri.c \
			ft_putendl_fd.c ft_itoa.c ft_putnbr_fd.c ft_strmapi.c ft_split.c \
			ft_printf.c ft_printf_util.c ft_formatter_1.c ft_formatter_2.c

BONUS = 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

SOURCE_O = $(SOURCE:.c=.o)

BONUS_O = $(BONUS:.c=.o)

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

all: $(NAME)

%.o: %.c
	@echo "$(GREEN)Compiling:$(NORMAL)"
	gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME): $(SOURCE_O)
	@echo "$(BLUE)Adding to library...$(NORMAL)"
	@ar rc $(NAME) $(SOURCE_O) $?
	@echo "$(GREEN)Successfully added to library!"

clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	@/bin/rm -f $(SOURCE_O) $(BONUS_O)
	@echo "$(GREEN)Succesfully removed all object files!"

fclean: clean
	@echo "$(RED)Removing libft.a...$(NORMAL)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)Successfully removed libft.a!"

re: fclean all

bonus: $(NAME) $(BONUS_O)
	@echo "$(BLUE)Adding to library...$(NORMAL)"
	@ar rc $(NAME) $(BONUS_O) $?
	@echo "$(GREEN)Succesfully added to library!"

.PHONY: all clean fclean re bonus