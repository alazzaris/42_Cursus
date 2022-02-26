/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:18:34 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/25 18:55:52 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index(t_stack *lst_a, t_stack *lst_b, t_info *info)
{
	int		i;
	t_stack	*temp_b;
	int		up_a;
	int		up_b;
	int		min;

	i = 0;
	min = 2147483647;
	temp_b = lst_b;
	while (i < (info)->number_b)
	{
		up_b = ft_move_up(lst_b, temp_b->index);
		up_a = ft_move_up(lst_a, ft_find_position(lst_a, temp_b->index, info));
		if (ft_smaller(ft_move(up_a, up_b), &min))
			info->min_index = temp_b->index;
		temp_b = temp_b->next;
		i++;
	}
	return (info->min_index);
}

int	ft_find_position(t_stack *lst, int index, t_info *info)
{
	int		i;
	t_stack	*previous;

	i = 0;
	while (i < info->number_a)
	{
		previous = lst->previous;
		if (previous->index < index
			&& (lst->index < previous->index || index < lst->index))
			return (lst->index);
		if (lst->index > index
			&& (lst->index < previous->index || index > previous->index))
			return (lst->index);
		lst = lst->next;
	}
	return (0);
}

int	ft_back(t_stack **a, t_stack **b, t_info **info)
{
	int	a_index;
	int	b_index;
	int	up_a;
	int	up_b;

	b_index = ft_get_index(*a, *b, *info);
	a_index = ft_find_position(*a, b_index, *info);
	up_b = ft_move_up(*b, b_index);
	up_a = ft_move_up(*a, a_index);
	if ((up_a >= 0 && up_b >= 0) || (up_a <= 0 && up_b <= 0))
		(*info)-> count += ft_move_both(a, b, up_a, up_b);
	else
	{
		ft_bring(b, b_index, info, 0);
		ft_bring(a, a_index, info, 1);
	}
	(*info)-> count += ft_push(b, a, 1);
	return (1);
}

int	ft_bring(t_stack **element, int index, t_info **info, int a)
{
	int	up_element;
	int	i;

	up_element = ft_move_up(*element, index);
	i = 0;
	if (up_element < 0)
		while (i++ < ft_sign(up_element))
			(*info)-> count += ft_reverse_rotate(element, a);
	else
		while (i++ < ft_sign(up_element))
			(*info)-> count += ft_rotate(element, a);
	return (1);
}

int	ft_move_both(t_stack **a, t_stack **b, int up_a, int up_b)
{
	int	(*f)(t_stack **arg, int a);
	int	i;

	i = 0;
	if (up_a >= 0 && up_b >= 0)
		f = ft_rotate;
	else
		f = ft_reverse_rotate;
	while (i < ft_sign(up_a) && i < ft_sign(up_b))
	{
		f(a, -1);
		f(b, -1);
		if (up_a > 0)
			write(1, "rr\n", 3);
		else
			write(1, "rrr\n", 4);
		i++;
	}
	while (i < ft_sign(up_a) && i++ >= 0)
		f(a, 1);
	while (i < ft_sign(up_b) && i++ >= 0)
		f(b, 0);
	return (i);
}
