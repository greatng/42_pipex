NAME 	=	gnl.a

SOURCE 	=	get_next_line.c get_next_line_utils.c

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
	@echo "$(BLUE)Adding to gnl library...$(NORMAL)"
	@ar rc $(NAME) $(SOURCE_O) $?
	@echo "$(GREEN)Successfully added to gnl library!"

clean:
	@echo "$(RED)Removing all gnl object files...$(NORMAL)"
	@/bin/rm -f $(SOURCE_O) $(BONUS_O)
	@echo "$(GREEN)Succesfully removed all gnl object files!"

fclean: clean
	@echo "$(RED)Removing gnl.a...$(NORMAL)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)Successfully removed gnl.a!"

re: fclean all

.PHONY: all clean fclean re bonus