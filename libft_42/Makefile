# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 18:59:32 by coder             #+#    #+#              #
#    Updated: 2022/10/06 00:04:27 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_memset.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strchr.c\
		ft_strnstr.c ft_strncmp.c ft_memcmp.c ft_memchr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strrchr.c\
		ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c	ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c\
		ft_strmapi.c ft_itoa.c ft_strtrim.c ft_split.c

OBJ	= $(SRC:%.c=%.o)

SRCBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
			ft_lstmap.c ft_lstsize.c

OBJBONUS = $(SRCBONUS:%.c=%.o)

FLAG = -Wall \
	-Werror \
	-Wextra \
	-g3

all:	$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):	$(SRC)
	gcc $(FLAG) -c $(SRC)

bonus: $(OBJBONUS)

$(OBJBONUS):
		gcc $(FLAG) -c $(@:%.o=%.c)
		ar rcs $(NAME) $@

clean:
	rm -rf $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
