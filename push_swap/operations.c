/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:41:47 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/13 19:18:40 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a, t_stack *b, char *action)
{
	if (!ft_strcmp(action, "sa\n") || !ft_strcmp(action, "ss\n"))
		ft_swap(&a->stack[0], &a->stack[1]);
	if (!ft_strcmp(action, "sb\n") || !ft_strcmp(action, "ss\n"))
		ft_swap(&b->stack[0], &b->stack[1]);
}

void	ft_operation(t_stack *a, t_stack *b, char *action)
{
	if (!ft_strcmp(action, "sa\n") || !ft_strcmp(action, "sb\n"))
		swap(a, b, action);
	else if (!ft_strcmp(action, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(action, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(action, "ra\n") || !ft_strcmp(action, "rb\n")
		|| !ft_strcmp(action, "rr\n"))
		rotate(a, b, action);
	else if (!ft_strcmp(action, "rra\n") || !ft_strcmp(action, "rrb\n")
		|| !ft_strcmp(action, "rrr\n"))
		reverse_rotate(a, b, action);
	write(1, action, ft_strlen(action));
}

void	push(t_stack *from, t_stack *to)
{
	unsigned int	i;

	if (!from->size)
		return ;
	i = to->size;
	to->size++;
	while (i)
	{
		ft_swap(&to->stack[i], &to->stack[i - 1]);
		i--;
	}
	ft_swap(&from->stack[0], &to->stack[0]);
	while (i < from->size - 1)
	{
		ft_swap(&from->stack[i], &from->stack[i + 1]);
		i++;
	}
	from->size--;
}

void	rotate(t_stack *a, t_stack *b, char *action)
{
	unsigned int	i;

	if (a && (!ft_strcmp(action, "ra\n") || !ft_strcmp(action, "rr\n")))
	{
		i = 1;
		while (i < a->size)
		{
			ft_swap(&a->stack[i - 1], &a->stack[i]);
			i++;
		}
	}
	if (b && (!ft_strcmp(action, "rb\n") || !ft_strcmp(action, "rr\n")))
	{
		i = 1;
		while (i < b->size)
		{
			ft_swap(&b->stack[i - 1], &b->stack[i]);
			i++;
		}
	}
}

void	reverse_rotate(t_stack *a, t_stack *b, char *action)
{
	unsigned int	i;

	if (a && (!ft_strcmp(action, "rra\n") || !ft_strcmp(action, "rrr\n")))
	{
		i = a->size;
		while (i)
		{
			ft_swap(&a->stack[i], &a->stack[i - 1]);
			i--;
		}
		ft_swap(&a->stack[0], &a->stack[a->size]);
	}
	if (b && (!ft_strcmp(action, "rrb\n") || !ft_strcmp(action, "rrr\n")))
	{
		i = b->size;
		while (i)
		{
			ft_swap(&b->stack[i], &b->stack[i - 1]);
			i--;
		}
		ft_swap(&b->stack[0], &b->stack[b->size]);
	}
}
