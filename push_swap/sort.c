/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:32:38 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/15 01:40:38 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_structs *s)
{
	unsigned int	highest;
	unsigned int	lowest;

	while (!ft_is_sort(s->a))
	{
		highest = ft_highest(&s->a);
		lowest = ft_lowest(&s->a);
		if (highest == 0 && lowest == 1)
			ft_operation(&s->a, &s->b, "ra\n");
		else if (highest == 1 && lowest == 2)
			ft_operation(&s->a, &s->b, "rra\n");
		else
			ft_operation(&s->a, &s->b, "sa\n");
	}
}

void	ft_five(t_structs *s)
{
	unsigned int	lowest;

	while (!ft_is_sort(s->a) || s->b.size)
	{
		lowest = ft_lowest(&s->a);
		if (s->b.size == 2)
		{
			ft_three(s);
			ft_operation(&s->a, &s->b, "pa\n");
			ft_operation(&s->a, &s->b, "pa\n");
		}
		else if (!lowest && s->b.size < 2)
			ft_operation(&s->a, &s->b, "pa\n");
		else if (s->b.size < 2 && lowest < 3 && lowest)
			ft_operation(&s->a, &s->b, "ra\n");
		else if (s->b.size < 2 && lowest < 2 && lowest)
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
	ft_to_top(s, ft_highest(&s->b), s->b.size, 'b');
	while (s->b.size)
		ft_operation(&s->a, &s->b, "pa\n");
}
