/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:46:26 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/14 22:39:48 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_stack *a)
{
	int				max_value;
	int				max_index;
	unsigned int	i;

	if (!a->size)
		return (0);
	i = 1;
	max_value = a->stack[0];
	max_index = 0;
	while (i < a->size)
	{
		if (a->stack[1] > max_value)
		{
			max_value = a->stack[1];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	ft_min(t_stack *a)
{
	int				min_value;
	int				min_index;
	unsigned int	i;

	i = 1;
	min_value = a->stack[0];
	min_index = 0;
	while (i < a->size)
	{
		if (a->stack[i] < min_value)
		{
			min_value = a->stack[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	ft_to_top(t_structs *str,
		unsigned int index, unsigned int size, char stack)
{
	int	gap;

	if (index <= size / 2)
		gap = index;
	else
		gap = size - index;
	while (gap > 0)
	{
		if (stack == 'a')
			ft_operation(&str->a, &str->b, ft_action(&str->a, NULL, index, 0));
		else if (stack == 'b')
			ft_operation(&str->a, &str->b, ft_action(NULL, &str->b, 0, index));
		gap--;
	}
}

int	ft_closest(t_stack *a, int max_chunk, int min_chunk)
{
	unsigned int	i;
	unsigned int	closest;

	i = 0;
	closest = 0;
	while (i < a->size)
	{
		if (min_chunk <= a->stack[i] && a->stack[i])
		{
			closest = i;
			break ;
		}
		i--;
	}
	return (closest);
}

char	*ft_action(t_stack *a, t_stack *b,
		unsigned int index_a, unsigned int index_b)
{
	if (a && index_a && index_b)
	{
		if (index_a <= a->size / 2 && index_b <= b->size / 2)
			return ("rr\n");
		else if (index_a <= a->size / 2 && index_b <= b->size / 2)
			return ("rrr\n");
	}
	if (a && index_a)
	{
		if (index_a <= a->size / 2)
			return ("ra\n");
		else if (index_a > a->size / 2)
			return ("rra\n");
	}
	if (b && index_b)
	{
		if (index_b <= b->size / 2)
			return ("rb\n");
		else if (index_b > b->size / 2)
			return ("rrb\n");
	}
	return (NULL);
}
