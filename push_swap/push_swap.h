/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:36:35 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/14 23:46:12 by alazzari         ###   ########.fr       */
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
int		ft_closest(t_stack *a, int max_chunk, int min_chunk);
char	*ft_action(t_stack *a, t_stack *b,
			unsigned int index_a, unsigned int index_b);

//Init.c
void	ft_index(t_structs *s, t_stack *a);
int		ft_is_sort(t_stack a);
int		ft_is_overflow(const char *str);
void	ft_stacks(t_structs *s, int size);
void	ft_check(t_structs *s, int argc, char **argv);

//Sort.c
void	ft_three(t_structs *s);
void	ft_five(t_structs *s);
void	ft_hundred(t_structs *s, int chunk_size);

//Max_sort.c
void	ft_closest_hundred(t_structs *s, int max_chunk);
int		ft_previous(t_stack *b, int number);

//Main.c
void	ft_exit(t_structs *s, char *error_message, int status);
void	ft_sort(t_structs *s);
int		main(int argc, char **argv);

#endif