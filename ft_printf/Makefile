# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:04:28 by alazzari          #+#    #+#              #
#    Updated: 2022/01/24 17:37:34 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rcs

LIBFT_DIR = libft

SRC_DIR = src

OBJ_DIR = obj

SRC_FILES = ft_printf.c \

OBJ_FILES = $(SRC_FILES:%.c=%.o)

LIBFT_FILES = libft.a

SRC = $(addprefix $(SRC_DIR))/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_DIR))/, $(OBJ_FILES))

LIBFT = $(addprefix $(LIBFT_DIR))/, $(LIBFT_FILES))

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) .
	cp $(LIBFT_NAME) $(NAME)
	ar $(ARFLAGS) $@ $(OBJ)

bonus: $(NAME)

$(LIBFT):
	all -sC $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	clean -sC $(LIBFT_DIR)
	rm -rf $(LIBFT_NAME)
	rm -rf $(OBJ_DIR)

fclean: clean
	fclean -sC $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all