/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:46:26 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/13 20:44:19 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *a)
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

int	get_min(t_stack *a)
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
			ft_operation(&str->a, &str->b, get_action(&str->a, NULL, index, 0));
	}
}
