/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 00:50:08 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/26 02:23:39 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (argc < 2 || i < 1)
		return (ft_free(&first_a, &info));
	info->number_a = i + 1;
	ft_sort(first_a, first_b, info);
	ft_free(&first_a, &info);
	return (0);
}


