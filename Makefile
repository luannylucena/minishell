NAME = minishell

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libft/

VPATH = $(addprefix $(PATH_SRCS), \
		./ \
		./init/ \
		./sources/ \
		./parser/ \
		./builtins/ \
		./utils/ \
		./prompt/)

SRCS = 	minishell.c \
		init.c \
		signals.c \
		parser.c \
		pwd.c \
		cd.c \
		echo.c \
		exit.c \
		env.c \
		unset.c \
		unset_utils.c \
		export.c \
		export_utils.c \
		execute_builtin.c \
		data.c \
		input.c \
		free_minishell.c \

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

run: all 
	$(CVALGRIND) ./$(NAME)

valgrind: all
	@valgrind -q --leak-check=full --show-leak-kinds=all --trace-children=yes \
	--suppressions=ignorelibs.txt --track-fds=yes --track-origins=yes \
	--trace-children-skip='*/bin/*,*/sbin/*' \
	./minishell

clean:
	rm -rf $(PATH_OBJS)
	make clean -C $(PATH_LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(PATH_LIBFT)

re: fclean all

.PHONY: all clean fclean re