# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 22:26:55 by alazzari          #+#    #+#              #
#    Updated: 2022/02/16 23:03:51 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	=	PUSH_SWAP

LIBFT		=	./libft

LIBFT_LIB	=	libft.a

SRC	=	main.c \
		init.c \
		operations.c \
		sort_1.c \
		sort_2.c \
		sort_3.c \
		utils.c \

OBJ		=	$(SRC:.c=.o)
RM		=	rm -f
LIB		=	ar -rcs
FLAGS	=	-Wall -Wextra -Werror
INCS	= 	.

.c.o:
	${CC} $(FLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(PUSH_SWAP):	${OBJ}
				make all -C $(LIBFT)/
				cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
				$(LIBC) $(NAME) $(OBJ)

all: $(NAME)

fclean:	clean
		$(RM) $(NAME)
		make clean -C $(LIBFT)
	
clean:
		$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re .c.o