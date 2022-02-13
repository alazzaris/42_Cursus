# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:05:27 by alazzari          #+#    #+#              #
#    Updated: 2022/01/27 17:58:27 by alazzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft

LIBFT_LIB = libft.a

SRCS = ft_printf.c \
		ft_printf_hex.c \
		ft_printf_ptr.c \
		ft_printf_unsigned.c \
		ft_printf_utils.c \

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= ./

.c.o :
	${CC} $(FLAGS) -c $< -o $(<:.c=.o) -I$(INCS)


$(NAME): ${OBJS}
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)
    
fclean: clean
	$(RM) $(NAME)
	make clean -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o
