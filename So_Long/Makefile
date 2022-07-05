# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 01:19:38 by alazzari          #+#    #+#              #
#    Updated: 2022/03/26 14:42:04 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	./Src/Mandatory/get_next_line_utils.c \
			./Src/Mandatory/get_next_line.c \
			./Src/Mandatory/hook.c \
			./Src/Mandatory/Init.c \
			./Src/Mandatory/main.c \
			./Src/Mandatory/movement.c \
			./Src/Mandatory/rendering.c \
			./Src/Mandatory/map_element.c \
			./Src/Mandatory/map_structure.c \
			./Src/Mandatory/errors_2.c \
			./Src/Mandatory/errors_1.c \

SRCS_B	=	./Src/Bonus/loops_bonus.c \
			./Src/Bonus/get_next_line_utils_bonus.c \
			./Src/Bonus/get_next_line_bonus.c \
			./Src/Bonus/hook_bonus.c \
			./Src/Bonus/init_bonus.c \
			./Src/Bonus/main_bonus.c \
			./Src/Bonus/movement_bonus.c \
			./Src/Bonus/rendering_bonus.c \
			./Src/Bonus/map_element_bonus.c \
			./Src/Bonus/map_structure_bonus.c \
			./Src/Bonus/errors_2_bonus.c \
			./Src/Bonus/errors_1_bonus.c \

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

OBJS_B	=	$(patsubst %.c, %.o, $(SRCS_B))

CC		=	gcc

FLAGS	=	-g -Wall -Wextra -Werror

LIBFT	=	./Src/Libft/libft.a

MINILIBX	=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(MINILIBX) $(LIBFT) $(OBJS) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $@

$(LIBFT):
	make -C ./Src/Libft

clean:
	rm -f $(OBJS) $(OBJS_B)
	make -C ./Src/Libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(LIBFT) $(OBJS_B)
	$(CC) $(FLAGS) $(MINILIBX) $(LIBFT) $(OBJS_B) -o $(NAME) $(LIBFT)

.PHONY: all clean fclean re bonus