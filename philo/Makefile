NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra  #-fsanitize=address #-g3 

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
UTILS		=	arguments.c error.c time.c mutex.c philos_utils.c dead_utils.c ft_utils.c ft_strtrim.c ft_substr.c ft_strdup.c

# PATH
SRC_PATH	=	$(addprefix src/, $(SRC))
UTILS_PATH	=	$(addprefix utils/, $(UTILS))

# OBJ
OBJ			=	$(SRC_PATH:.c=.o) $(UTILS_PATH:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

norm:
	@norminette

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean norm