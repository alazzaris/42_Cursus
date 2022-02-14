/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:36:35 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/14 21:05:41 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_chunk
{
	unsigned int	min;
	unsigned int	max;
	int				mid;
}	t_chunk;

typedef struct s_stack
{
	int				*stack;
	unsigned int	size;		
}	t_stack;

typedef struct s_structs
{
	t_stack			a;
	t_stack			b;
	unsigned int	size;
}	t_structs;

//Operation.c
void	ft_operation(t_stack *a, t_stack *b, char *action);
void	swap(t_stack *a, t_stack *b, char *action);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *a, t_stack *b, char *action);
void	reverse_rotate(t_stack *a, t_stack *b, char *action);

//Utils.c
int		ft_max(t_stack *a);
int		ft_min(t_stack *a);
void	ft_to_top(t_structs *s,
			unsigned int index, unsigned int size, char stack);
int		ft_near(t_stack *a, int max_chunk, int min_chunk);
char	*ft_action(t_stack *a, t_stack *b,
			unsigned int index_a, unsigned int index_b);

//Init.c

#endif