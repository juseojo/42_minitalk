# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongjch <seongjch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 11:15:50 by seongjch          #+#    #+#              #
#    Updated: 2022/08/04 11:30:07 by seongjch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=
CLIENT	=	client
SERVER	=	server

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

SRC_C	=	client.c
SRC_S	=	server.c

OBJS_S = $(SRC_S:.c=.o)
OBJS_C = $(SRC_C:.c=.o)

all: $(SERVER) $(CLIENT)

$(NAME) : all

$(SERVER) : $(OBJS_S)
	@make -C ./libft/
	@make -C ./ft_printf/
	@$(CC) $(CFLAGS) $(OBJS_S) libft/libft.a ft_printf/libftprintf.a -o $(SERVER)
$(CLIENT) : $(OBJS_C)
	@$(CC) $(CFLAGS) $(OBJS_C) libft/libft.a ft_printf/libftprintf.a -o $(CLIENT)

clean :
	@make -C ./libft/ clean
	@make -C ./ft_printf/ clean
	@rm -rf $(OBJS_S)
	@rm -rf $(OBJS_C)

fclean : clean
	@make -C ./libft/ fclean
	@make -C ./ft_printf/ fclean
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)

re : fclean all
