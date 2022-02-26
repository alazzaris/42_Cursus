/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:18:38 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/25 16:18:39 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **element, int a)
{
	t_stack	*next_1;
	t_stack	*next_2;
	t_stack	*previous_1;

	if (*element == NULL || (*element)->next == *element)
		return (0);
	else if ((*element)->next->next == *element)
		*element = (*element)->next;
	else
	{
		next_1 = (*element)->next;
		previous_1 = (*element)->previous;
		next_2 = next_1->next;
		previous_1->next = next_1;
		next_1->previous = previous_1;
		next_1->next = *element;
		(*element)->previous = next_1;
		next_2->previous = *element;
		(*element)->next = next_2;
		*element = next_1;
		return (1);
	}
	return (0);
}

int	ft_rotate(t_stack **element, int a)
{
	if (!(*element) || (*element)->number == (*element)->next->number)
		return (0);
	else
	{
		*element = (*element)->next;
		if (a == 1)
			write(1, "ra\n", 3);
		else if (a == 0)
			write(1, "rb\n", 3);
	}
	return (1);
}

int	ft_reverse_rotate(t_stack **element, int a)
{
	if (!(*element) || (*element)->number == (*element)->next->number)
		return (0);
	else
	{
		*element = (*element)->previous;
		if (a == 1)
			write(1, "rra\n", 4);
		else if (a == 0)
			write(1, "rrb\n", 4);
	}
	return (1);
}

static void	ft_check_push(t_stack **src, t_stack **dst)
{
	t_stack	*dst_previous;

	if (*dst)
	{
		dst_previous = (*dst)->previous;
		dst_previous->next = (*src);
		(*src)->previous = dst_previous;
		(*dst)->previous = (*src);
		(*src)->next = *dst;
		*dst = *src;
	}
	else
	{
		*dst = *src;
		(*dst)->next = *dst;
		(*dst)->previous = *dst;
	}
}

int	ft_push(t_stack **src, t_stack **dst, int a)
{
	t_stack	*src_previous;
	t_stack	*src_next;

	if (!(*src))
		return (0);
	src_previous = (*src)->previous;
	src_next = (*src)->next;
	ft_check_push(src, dst);
	if ((*src)->number == src_next->number)
		*src = NULL;
	else
	{
		src_previous->next = src_next;
		src_next->previous = src_previous;
		*src = src_next;
	}
	if (a)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return (1);
}
