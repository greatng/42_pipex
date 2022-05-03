NAME			=	pipex
NAME_B			=	pipex_bonus

LEAKS			=	-fsanitize=address -fno-omit-frame-pointer
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_DIR		=	includes
HEADER			=	pipex
HEADERS			=	$(addprefix $(HEADER_DIR)/, $(addsuffix .h, $(HEADER)))

SRC_DIR			=	src
SRC			=	pipex_main pipex_router pipex_err
SRC_B			=	pipex_main pipex_router pipex_err pipex_heredoc
SRCS 			=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
SRCS_B			=	$(addprefix $(SRC_DIR)/, $(addsuffix _bonus.c, $(SRC_B)))

OBJ_DIR			=	obj
OBJ			=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC)))
OBJ_B			=	$(addprefix $(OBJ_DIR)/, $(addsuffix _bonus.o, $(SRC_B)))

GNL_PATH		=	./gnl
GNL			=	$(GNL_PATH)/gnl.a

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m
SALMON = \033[38;5;174m
HOTPINK = \033[38;5;168m


all:				$(NAME)

$(NAME):			$(LIBFT) $(GNL) $(OBJ)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) $(CFLAGS) $(LIBFT) $(GNL) $(OBJ) -o $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c	$(HEADERS)
					@mkdir -p $(OBJ_DIR)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) $(CFLAGS) -c $< -o $@ 			
					
$(LIBFT):
					@make -C $(LIBFT_PATH) all
$(GNL):
					@make -C $(GNL_PATH) all

bonus:				$(NAME_B)

$(NAME_B):			$(LIBFT) $(GNL) $(OBJ_B)
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) $(CFLAGS) $(LIBFT) $(GNL) $(OBJ_B) -o $@
					@make pig

leaks:				$(NAME)
					@echo "$(GREEN)For Leaks Check:$(NORMAL)"
					$(CC) $(LEAKS) $(SRCS) $(GNLS) $(LIBFT) -o $(NAME)

clean:
					@make -C $(LIBFT_PATH) clean
					@make -C $(GNL_PATH) clean
					@$(RM) -f $(OBJ) $(OBJ_B) $(OBJ_DIR)
fclean:				clean
					@make -C $(LIBFT_PATH) fclean
					@make -C $(GNL_PATH) fclean
					@$(RM) -f $(NAME) $(NAME_B)

re:					fclean all

.PHONY:				all clean fclean re libft leaks bonus

pig:				
					@echo "$(SALMON)                         .....            :!????7!^:\n\
                   .^!J5PGGBGG5::~!77?77~:G&&&&&&&&#GY!.\n\
                 .?G#&&&&&&&&&B^G&&&&&&&B^G&&&&&&&&&&&#^\n\
                 .P&&&&&&&&&&#!?&&&&&&&&&J~B&&&&&&&&#Y^\n\
                  .JB&&&&&&&G!J&&&&&&&&&&&Y!YB###B5J??^\n\
                   ~??5GGG5?7P&&&&&&&&&&&&&#5JJJJJ5G&&#5^\n\
                 .J&&BPYYY5G&&&&&&&&&&&&&&&&&&&#&&&&&&&&#~\n\
                .Y&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&B^\n\
                !&&&&&&&&&&&&BG#&&&&&&&&&BJY#&&&&&&&&&&&&&P.\n\
               .5&&&&&&&&&&&#^ ?&&&&&&&&&5:^B&&&&&&&&&&&&&&Y.\n\
               ^#&&&&&&&&&&&&BPB$(HOTPINK)#BGGGGGGGBB$(SALMON)#&&&&&&&&&&&&&&&&J.\n\
              .5&&&&&&&&&&&&&$(HOTPINK)#BPPPP5PP55PPPPB$(SALMON)&&&&&&&&&&&&&&&&!\n\
              7&&&&&&&&&&&&&&$(HOTPINK)#PPPP?^5P!~PPPPG&$(SALMON)&&&#######&&&&&5.\n\
             .Y&&&&&#######&&&$(HOTPINK)BGPP55PPP5PPGB#$(SALMON)&&&#BBGBGBB##&&&B:\n\
              J&&&##BBBBBB##&&&&$(HOTPINK)#BBBBBB#PB$(SALMON)&&&&&##BGGPPGBB#&&&P.\n\
              :B&&#BBGPPGGB##&&&&#JYPPPJ?B&&&&&&#BBGGGBB##&&#!\n\
               ^G&&#BBGGGBB#&&&&&&#BPPGB&&&&&&&&########BBP!.\n\
                .?G########&&&&&&&&&&&&&&&&&&&&&&&&#G5YJJJYY5PY!.\n\
                   ^7J5GB#&&&&&&&&&&&&&&&&&&&&&&&&#YJPG##&&&&&@P.\n\
               :~!!777777?B&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&#GJ:\n\
             .J#&&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&#BBP5?!^.\n\
             .7B#&&&&&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&Y^.\n\
               .^~!777777Y#&&&&&&&&&&&&&&&&&&&&&&&&&&&?\n\
                        ~&&&&&&&&&&&&&&&&&&&&&&&&&&&&&P.\n\
                        ^#&&&&&&&&&&&&&&&&&&&&&&&&&&&&G.\n\
                         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~^\n\
					  pipex$(NORMAL)"