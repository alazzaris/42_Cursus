/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:18:51 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/25 18:14:05 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_element(t_info **info)
{
	t_stack	*lst;

	lst = NULL;
	lst = (t_stack *)malloc(sizeof(t_stack));
	if (lst == NULL)
	{
		(*info)->err = 0;
		return (NULL);
	}
	lst->number = 0;
	lst->index = 0;
	lst->flag = 1;
	lst->previous = lst;
	lst->next = lst;
	return (lst);
}

int	ft_a(t_stack **first_a, char *s, int *i, t_info **info)
{
	t_stack	*new;

	new = NULL;
	if (!(*first_a))
	{
		*first_a = ft_element(info);
		ft_smaller(ft_number(s, *first_a), &((*info)->err));
		(*first_a)->index = 0;
	}
	else
	{
		new = ft_element(info);
		(*first_a)->previous->next = new;
		new->previous = (*first_a)->previous;
		new->next = (*first_a);
		(*first_a)->previous = new;
		ft_smaller(ft_number(s, new), &((*info)->err));
		(*i)++;
		new->index = *i;
		ft_index(*first_a, *i, new->number);
	}
	return ((*info)->err);
}

int	ft_split(t_stack **first_a, char *s, int *i, t_info **info)
{
	char	*start;

	while (*s)
	{
		if (*s != ' ')
		{
			start = s;
			while ((*s != ' ') && *s)
				s++;
			if (*s)
			{
				*s = '\0';
				s++;
			}
			if (!ft_a(first_a, start, i, info))
				return (0);
		}
		else
			s++;
	}
	return (1);
}

int	ft_number(char *s, t_stack *element)
{
	long int	number;
	int			minus;

	number = 0;
	minus = 1;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		s++;
		minus = -1;
	}
	while (*s == '0')
		s++;
	if (*s > '0' && *s <= '9')
		number = *(s++) - 48;
	while (*s >= '0' && *s <= '9')
		number = number * 10 + (*s++ - 48);
	if (*s || !element || (number * minus) < -2147483648
		|| (number * minus) > 2147483647)
		return (0);
	element->number = (int)(number * minus);
	return (1);
}

void	ft_index(t_stack *element, int curr_index, int curr_number)
{
	t_stack	*temp;
	int		pos;
	int		i;

	temp = element;
	i = -1;
	while (++i < curr_index)
	{
		while (temp->index != i)
			temp = temp->next;
		if (curr_number < temp->number)
		{
			pos = temp->index;
			element->previous->index = pos;
			temp = element;
			while (temp->next->number != element->number)
			{
				if (temp->index >= pos && temp->index < curr_index)
					(temp->index)++;
				temp = temp->next;
			}
			return ;
		}
	}
}
