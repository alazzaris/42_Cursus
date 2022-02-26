# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 01:09:46 by alazzari          #+#    #+#              #
#    Updated: 2022/02/26 01:14:04 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CHECKER		= 	checker

SRCS		=	main.c \
				parsing.c \
				prepare.c \
			  	algorithm.c \
				commands.c \
				utils.c \
				free.c \

SRCS_B		=	checker.c \
				


OBJS		= ${SRCS:.c=.o}


CC			= gcc

FLAGS		= -Wall -Wextra -Werror

HEADER 		= push_swap.h

GNL			= get_next_line.h


%.o:%.c		${HEADER}
			@${CC} ${FLAGC} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(HEADER)
			${CC} ${FLAGS} -o ${NAME} $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS)

bonus:

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
