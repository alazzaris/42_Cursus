# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 16:03:09 by alazzari          #+#    #+#              #
#    Updated: 2022/05/19 17:34:28 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

CC	=	gcc

FLAGS	=	-Wall -Wextra -Werror #-fsanitize=address

SOURCES	=	philo_bonus.c \
			utils.c \
			life_bonus.c \
			death_bonus.c \
			time_bonus.c \
			process.c \
			semaphore.c \

OBJECTS = $(SOURCES:.c=.o)

HEADER = philo_bonus.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
