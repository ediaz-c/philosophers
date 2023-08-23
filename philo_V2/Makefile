NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g3

# DEBUG
DEBUG		=	-g3

# SANITIZE
## ADDRESS
ADDRESS	=	-fsanitize=address
## THREAD
THREAD	= 	-fsanitize=thread

# RM
RM = rm -rf

#FILES
SRC			=	main.c vars.c rutine.c actions.c dead.c
UTILS		=	arguments.c error.c time.c mutex.c philos_utils.c dead_utils.c
LIBFT		=	libft/libft.a

# PATH
SRC_PATH	=	$(addprefix src/, $(SRC))
UTILS_PATH	=	$(addprefix utils/, $(UTILS))

# OBJ
OBJ			=	$(SRC_PATH:.c=.o) $(UTILS_PATH:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
$(LIBFT):
	#@if [ -f ./libft/libft.a ]; then; else make -C libft; fi;
	@make -C libft

norm:
	@norminette

s_address: all
	@$(CC) $(CFLAGS) $(ADDRESS) $(LIBFT) $(OBJ) -o $(NAME)

s_thread: all
	@$(CC) $(CFLAGS) $(THREAD) $(LIBFT) $(OBJ) -o $(NAME)

debug:	all
	@$(CC) $(CFLAGS) $(DEBUG) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@make clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: re clean fclean norm s_address s_thread