NAME = minishell

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libft/

VPATH = $(addprefix $(PATH_SRCS), \
		./ \
		./sources/ \
		./parse/ \
		./builtins/ \
		./utils/ \
		./prompt/)

SRCS = 	main.c \
		signals.c \
		parse.c \
		ft_pwd.c \
		ft_cd.c \
		ft_echo.c \
		ft_exit.c \
		data.c \
		prompt.c

OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

LIBFT = $(PATH_LIBFT)libft.a

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror
IFLAGS = -I $(PATH_INCL)
CVALGRIND = valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(PATH_LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline

$(OBJS): | $(PATH_OBJS)

$(PATH_OBJS)%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes \
	--suppressions=readline.supp --leak-check=full \
	--show-leak-kinds=all --quiet ./minishell

clean:
	rm -rf $(PATH_OBJS)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all clean fclean re