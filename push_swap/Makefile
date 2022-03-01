# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 01:09:46 by alazzari          #+#    #+#              #
#    Updated: 2022/03/01 00:40:58 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	main.c \
				parsing.c \
				prepare.c \
			  	algorithm.c \
				commands.c \
				utils.c \
				free.c \

OBJS		= 	${SRCS:.c=.o}

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

HEADER 		=	push_swap.h

%.o:%.c		${HEADER}
			@${CC} ${FLAGC} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(HEADER)
			${CC} ${FLAGS} -o ${NAME} $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)
			rm -f $(OBJS_B)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean bonus re
