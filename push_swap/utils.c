/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:19:03 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/25 18:17:22 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bigger(int a, int *b)
{
	if (a > *b)
	{
		*b = a;
		return (1);
	}
	return (0);
}

int	ft_smaller(int a, int *b)
{
	if (a < *b)
	{
		*b = a;
		return (1);
	}
	return (0);
}

int	ft_sign(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	ft_move_up(t_stack *lst, int index)
{
	int		i;
	int		j;
	t_stack	*temp;

	temp = lst;
	i = 0;
	while (temp->index != index)
	{
		temp = temp->next;
		i++;
	}
	temp = lst;
	j = 0;
	while (temp->index != index)
	{
		temp = temp->previous;
		j++;
	}
	if (j < i)
		return (j * -1);
	else
		return (i);
}

int	ft_move(int a, int b)
{
	unsigned int	c;

	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
	{
		if (ft_sign(a) >= ft_sign(b))
			return (ft_sign(a));
		else
			return (ft_sign(b));
	}
	else
		c = ft_sign(a) + ft_sign(b);
	return (c);
}
