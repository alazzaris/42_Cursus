/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 23:00:36 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/18 14:48:00 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	ft_chunk_one(t_structs *s, t_chunk chunk)
{
	chunk.min = chunk.max;
	if (!chunk.max)
		chunk.max = s->size / 2;
	else if (chunk.max < s->size - s->size / 32)
		chunk.max += chunk.max / 2;
	else
		chunk.max = s->size;
	chunk.mid = chunk.min + (chunk.max - chunk.min) / 2;
	return (chunk);
}

t_chunk	ft_chunk_two(t_structs *s, t_chunk chunk)
{
	chunk.max = chunk.min;
	if (!chunk.max)
		chunk.max = s->size;
	chunk.min -= s->size / 16;
	if (chunk.min > s->size)
		chunk.min = 0;
	chunk.mid = chunk.min + (chunk.max - chunk.min) / 2;
	return (chunk);
}

t_chunk	ft_chunk_three(t_structs *s, t_chunk chunk)
{
	chunk.min = chunk.max;
	if (chunk.min == s->size / 64)
		chunk.min = 0;
	chunk.max += s->size / 64;
	chunk.mid = chunk.min + (chunk.max - chunk.min) / 2;
	return (chunk);
}

void	push_chunk(t_structs *s, t_chunk chunk, char stack)
{
	unsigned int	temp;

	while (stack == 'b' && s->a.size && s->b.size < chunk.max)
	{
		ft_to_top(s, ft_closest(&s->a, chunk.max, chunk.min),
			s->a.size, 'a');
		ft_operation(&s->a, &s->b, "pb\n");
		temp = ft_closest(&s->a, chunk.max, chunk.min);
		if (s->b.stack[0] > chunk.mid && temp < s->a.size / 2 && temp)
			ft_operation(&s->a, &s->b, "rr\n");
		else if (s->b.stack[0] > chunk.mid)
			ft_operation(&s->a, &s->b, "rb\n");
	}
	while (stack == 'a' && s->b.size && s->a.size < s->size - chunk.min)
	{
		ft_to_top(s, ft_closest(&s->b, chunk.max, chunk.min),
			s->b.size, 'b');
		ft_operation(&s->a, &s->b, "pa\n");
		temp = ft_closest(&s->b, chunk.max, chunk.min);
		if (s->a.stack[0] > chunk.mid && temp < s->b.size / 2 && temp)
			ft_operation(&s->a, &s->b, "rr\n");
		else if (s->a.stack[0] > chunk.mid)
			ft_operation(&s->a, &s->b, "ra\n");
	}
}