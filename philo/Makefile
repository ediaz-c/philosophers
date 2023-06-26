NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3
RM			=	rm -rf
SRC			=	main.c init.c rutine.c
UTILS		=	check_args.c msg.c time.c
LIBFT		=	libft/libft.a
SRC_PATH	=	$(addprefix src/, $(SRC))
UTILS_PATH	=	$(addprefix utils/, $(UTILS))
OBJ			=	$(SRC_PATH:.c=.o) $(UTILS_PATH:.c=.o)
all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
	@make -C libft

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C libft

clean:
	@$(RM) $(OBJ)
	@make clean -C libft

re:	fclean all

.PHONY:	re clean fclean