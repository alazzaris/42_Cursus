# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 18:00:49 by alazzari          #+#    #+#              #
#    Updated: 2022/05/13 18:00:49 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC	=	gcc

FLAGS	=	-Wall -Wextra -Werror

SOURCES	=	philo.c \
			utils.c \
			forks.c \
			life.c \
			death.c \
			time.c \
			error.c \

OBJECTS = $(SOURCES:.c=.o)

HEADER = philo.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
