/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:18:47 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/25 18:55:27 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_info	*ft_info(void)
{
	t_info	*lst;

	lst = NULL;
	lst = (t_info *)malloc(sizeof(t_info));
	if (!lst)
		return (NULL);
	lst->number_a = 0;
	lst->number_a = 0;
	lst->max_pos = 0;
	lst->max_len = 0;
	lst->min_index = 0;
	lst->count = 0;
	lst->err = 1;
	return (lst);
}

static int	ft_check_double(t_stack *first_a, t_info *info)
{
	t_stack	*temp_i;
	t_stack	*temp_j;
	t_stack	*last;

	if (!first_a)
		return (0);
	temp_i = first_a;
	last = first_a->previous;
	while (temp_i != last)
	{
		temp_j = temp_i->next;
		while (temp_j != first_a)
		{
			if (temp_i->number == temp_j->number)
			{
				info->err = 0;
				return (0);
			}
			temp_j = temp_j->next;
		}
		temp_i = temp_i->next;
	}
	return (1);
}

static void	ft_three(t_stack **first_a, t_info **info)
{
	t_stack	*temp;

	temp = *first_a;
	if (temp->number > temp->next->number)
		temp = temp->next;
	else if (temp->next->number > temp->previous->number)
		temp = temp->previous;
	if (temp->number > temp->next->number
		|| temp->next->number > temp->previous->number)
	{
		ft_swap(first_a, 1);
		write (1, "sa\n", 3);
		(*info)->count += 1;
	}
}

static void	ft_sort(t_stack *first_a, t_stack *first_b, t_info *info)
{
	int	i;
	int	j;

	if (info->number_a == 3)
		ft_three(&first_a, &info);
	ft_best_index(first_a, info);
	ft_b(&first_a, &first_b, &info);
	i = 0;
	j = info->number_b;
	while (i++ < j)
	{
		ft_back(&first_a, &first_b, &info);
		info->number_b -= 1;
		info->number_a += 1;
	}
	ft_bring(&first_a, 0, &info, 1);
}

int	main(int argc, char **argv)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_info	*info;
	int		i;

	info = ft_info();
	if (!info)
		return (0);
	first_a = NULL;
	first_b = NULL;
	i = 0;
	while (*(++argv))
		ft_split(&first_a, *argv, &i, &info);
	ft_check_double(first_a, info);
	if (!info->err)
	{
		write(1, "Error\n", 6);
		return (ft_free(&first_a, &info));
	}
	if (argc < 2 || i < 1)
		return (ft_free(&first_a, &info));
	info->number_a = i + 1;
	ft_sort(first_a, first_b, info);
	ft_free(&first_a, &info);
	return (0);
}
