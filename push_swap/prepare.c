/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:18:57 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/28 22:45:54 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_longest(int max, int j, int *array)
{
	int	i;

	i = max;
	while (j >= 0)
	{
		if (array[j] == i)
			i--;
		else
			array[j] = -1;
		j--;
	}
}

int	ft_longest(t_stack **element, t_info **info, int *array, int max)
{
	t_stack	*temp_i;
	t_stack	*temp_j;
	int		i;
	int		j;

	temp_j = (*element)->next;
	j = 1;
	while (j < (*info)->number_a)
	{
		array[j] = 1;
		i = 0;
		temp_i = *element;
		while (temp_i->index != temp_j->index)
		{
			if (temp_i->index < temp_j->index && array[j] <= array[i])
				array[j] = array[i] + 1;
			ft_bigger(array[j], &max);
			i++;
			temp_i = temp_i->next;
		}
		temp_j = temp_j->next;
		j++;
	}
	ft_check_longest(max, j - 1, array);
	return (max);
}

static void	ft_check_index(t_stack **temp, t_info **info, int *array, int k)
{
	while (++k < (*info)->number_a)
	{
		if (array[k] == -1)
			(*temp)->flag = 0;
		*temp = (*temp)->next;
	}
}

int	ft_best_index(t_stack *element, t_info *info)
{
	t_stack	*temp;
	int		k;
	int		max;
	int		*array;

	array = (int *)malloc(sizeof(int) * (info->number_a));
	k = 0;
	temp = element;
	while (k++ < info->number_a)
	{
		array[0] = 1;
		max = ft_longest(&temp, &info, array, 0);
		if (ft_bigger(max, &info->max_len))
			info->max_pos = temp->index;
		temp = temp->next;
	}
	while (temp->index != info->max_pos)
		temp = temp->next;
	array[0] = 1;
	ft_longest(&temp, &info, array, 0);
	ft_check_index(&temp, &info, array, -1);
	free(array);
	return (info->max_len);
}

int	ft_b(t_stack **first_a, t_stack **first_b, t_info **info)
{
	int		i;
	t_stack	*temp;

	(*info)->number_b = (*info)->number_a - (*info)->max_len;
	(*info)->number_a = (*info)->max_len;
	*first_b = NULL;
	i = 0;
	while (i < (*info)->number_b)
	{
		temp = *first_a;
		while (temp->flag == 1)
			temp = temp->next;
		ft_bring(first_a, temp->index, info, 1);
		(*info)->count += ft_push(first_a, first_b, 0);
		i++;
	}
	return (0);
}
