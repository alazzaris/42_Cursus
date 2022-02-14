/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:11:34 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/14 23:56:55 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_closest_hundred(t_structs *s, int max_chunk)
{
	unsigned int	closest;
	char			*action;

	closest = ft_closest(&s->a, max_chunk, 0);
	while (closest)
	{
		action = ft_action(&s->a, &s->b,
				closest, ft_previous(&s->b, s->a.stack[closest]));
		if (closest > s->b.size && !ft_strcmp(action, "ra\n")
			&& ft_previous(&s->b, s->a.stack[closest]))
			ft_operation(&s->a, &s->b, "rr\n");
		else if (s->a.size - closest > s->b.size && !ft_strcmp(action, "rra\n")
			&& ft_previous(&s->b, s->a.stack[closest]))
			ft_operation(&s->a, &s->b, "rrr\n");
		else
			ft_operation(&s->a, &s->b, action);
		closest = ft_closest(&s->a, max_chunk, 0);
	}
}

int	ft_previous(t_stack *b, int number)
{
	unsigned int	i;
	int				prev_value;
	int				prev_index;
	int				prev;

	i = 0;
	prev_value = -1;
	prev_index = 0;
	prev = 0;
	while (b && i < b->size)
	{
		if (prev_value < b->stack[i] && b->stack[i] < number)
		{
			prev_value = b->stack[i];
			prev_index = i;
			prev = 1;
		}
		i++;
	}
	if (!prev)
		return (ft_highest(b));
	return (prev_index);
}
