# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 10:26:24 by alazzari          #+#    #+#              #
#    Updated: 2022/03/29 10:26:24 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			=	server
CLIENT			=	client

HEADER			=	minitalk.h

LIBFT			=	Libft/libft.a

FLAGS			=	-g -Wall -Wextra -Werror
CC				=	gcc
RM				=	rm -f

# COLORS
GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
RESET = \033[0m

all:	$(LIBFT) $(CLIENT) $(SERVER) $(HEADER)

$(SERVER):	server.c $(HEADER)
			@$(CC) server.c $(LIBFT) -o $@
			@echo "$(GREEN)Server is ready!$(RESET)"

$(CLIENT):	client.c $(HEADER)
			@$(CC) client.c $(LIBFT) -o $@
			@echo "$(GREEN)Client is ready!$(RESET)"

$(LIBFT):
			@make -C ./Libft

clean:
			@make clean -C ./Libft

fclean:		clean
			$(RM) $(SERVER) $(CLIENT)
			make fclean -C ./Libft

re: fclean all

.PHONY: all re clean fclean