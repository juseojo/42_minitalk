# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 01:43:36 by seongjuncho       #+#    #+#              #
#    Updated: 2022/02/10 01:51:33 by seongjuncho      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(shell find . -name "*.c")
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}
CFLAGS = -Wall -Werror -Wextra
COMPILE = gcc $(CFLAGS) -c
LIB = ar rc $(NAME)
RANLIB = ranlib $(NAME)
REMOVE = rm -f
all: $(NAME)
$(NAME):
	@$(COMPILE) $(SRC)
	@$(LIB) $(OBJ)
	@$(RANLIB)
clean:
	@$(REMOVE) $(OBJ)

fclean: clean
	@$(REMOVE) $(NAME)
re: fclean all
.PHONY: all clean fclean re
