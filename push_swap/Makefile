# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 01:09:46 by alazzari          #+#    #+#              #
#    Updated: 2022/02/26 02:50:04 by alazzari         ###   ########.fr        #
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
				ft_strcmp.c \

OBJS		= 	${SRCS:.c=.o}

OBJS_B		=	${SRCS_B:.c=.o}

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

HEADER 		=	push_swap.h

%.o:%.c		${HEADER}
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(HEADER)
			${CC} ${FLAGS} -o ${NAME} $(OBJS)

$(CHECKER):	$(OBJS_B) $(HEADER)
			@$(CC) $(FLAGS) -o ${CHECKER} $(OBJS) $(OBJS_B)

all:		$(NAME) $(CHECKER)

clean:
			rm -f $(OBJS)
			rm -f $(OBJS_B)

bonus:		$(CHECKER)

fclean:		clean
			rm -f $(NAME)
			rm -f $(CHECKER)

re:			fclean all

.PHONY: 	all clean fclean bonus re
