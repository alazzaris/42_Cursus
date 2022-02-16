/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:32:38 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/16 23:04:25 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_structs *s)
{
	unsigned int	max;
	unsigned int	min;

	while (!ft_is_sort(s->a))
	{
		max = ft_max(&s->a);
		min = ft_min(&s->a);
		if (max == 0 && min == 1)
			ft_operation(&s->a, &s->b, "ra\n");
		else if (max == 1 && min == 2)
			ft_operation(&s->a, &s->b, "rra\n");
		else
			ft_operation(&s->a, &s->b, "sa\n");
	}
}

void	ft_five(t_structs *s)
{
	unsigned int	min;

	while (!ft_is_sort(s->a) || s->b.size)
	{
		min = ft_min(&s->a);
		if (s->b.size == 2)
		{
			ft_three(s);
			ft_operation(&s->a, &s->b, "pa\n");
			ft_operation(&s->a, &s->b, "pa\n");
		}
		else if (!min && s->b.size < 2)
			ft_operation(&s->a, &s->b, "pa\n");
		else if (s->b.size < 2 && min < 3 && min)
			ft_operation(&s->a, &s->b, "ra\n");
		else if (s->b.size < 2 && min < 2 && min)
			ft_operation(&s->a, &s->b, "rra\n");
	}
}

void	ft_hundred(t_structs *s, int chunk_size)
{
	unsigned int	max_chunk;

	max_chunk = 0;
	while (s->a.size)
	{
		max_chunk += chunk_size;
		if ((float)s->a.size / 4 > 5)
			chunk_size = s->a.size / 5;
		while (s->a.size && s->b.size < max_chunk)
		{
			ft_closest_hundred(s, max_chunk);
			ft_to_top(s, ft_previous(&s->b, &s->a.stack[0]), s->b.size, 'b');
			ft_operation(&s->a, &s->b, "pb\n");
		}
	}
	ft_to_top(s, ft_max(&s->b), s->b.size, 'b');
	while (s->b.size)
		ft_operation(&s->a, &s->b, "pa\n");
}

