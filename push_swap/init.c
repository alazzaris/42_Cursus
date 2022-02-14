/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:48:08 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/14 21:32:28 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_structs *s, t_stack *a)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	index;
	int				*control;

	i = 0;
	control = ft_calloc (a->size, sizeof(int));
	if (!control)
		ft_exit (s, "error: malloc error\n", -1);
	while (i < a->size)
	{
		j = 0;
		index = 0;
		while (j < a->size)
		{
			if (a->stack[j] < a->stack[i])
				index++;
			j++;
		}
		control[i] = index;
		i++;
	}
	free (a->stack);
	a->stack = control;
}

int	ft_is_sort(t_stack a)
{
	unsigned int	i;

	i = 1;
	while (i < a.size)
	{
		if (a.stack[i - 1] >= a.stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_overflow()
{}

void    ft_stacks()
{}

void    ft_check()
{}
