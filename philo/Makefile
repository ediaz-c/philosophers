NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=thread -g
SANITIZE	=	-fsanitize=thread
RM			=	rm -rf
SRC			=	main.c init.c rutine.c dead.c
UTILS		=	check_args.c msg.c time.c
LIBFT		=	libft/libft.a
SRC_PATH	=	$(addprefix src/, $(SRC))
UTILS_PATH	=	$(addprefix utils/, $(UTILS))
OBJ			=	$(SRC_PATH:.c=.o) $(UTILS_PATH:.c=.o)
all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C libft

norm:	
	norminette

sanitize: 
	@$(CC) $(CFLAGS) $(SANITIZE) $(LIBFT) $(OBJ) -o $(NAME)

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft

clean:
	@$(RM) $(OBJ)
	@make clean -C libft

re:	fclean all

.PHONY:	re clean fclean norm sanitize