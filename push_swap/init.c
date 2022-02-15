/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:48:08 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/15 01:35:03 by alazzari         ###   ########.fr       */
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
		ft_exit (s, "Error\n", -1);
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

int	ft_is_overflow(const char *str)
{
	int	number;
	int	sign;

	sign = 1;
	number = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		number *= 10 + (*str - 48) * sign;
		str++;
		if ((number >= 0 && sign == -1) || (number < 0 && sign == 1))
			return (1);
	}
	return (0);
}

void	ft_stack(t_structs *s, int size)
{
	s->size = size;
	s->a.size = size;
	s->b.size = 0;
	s->a.stack = ft_calloc(size, sizeof(int));
	s->b.stack = ft_calloc(size, sizeof(int));
	if (!s->a.stack || !s->b.stack)
		ft_exit(s, "Error\n", -1);
}

void	ft_check(t_structs *s, int argc, char **argv)
{
	unsigned int	i;
	unsigned int	j;

	if (argc < 2)
		ft_exit(s, "", -1);
	i = 0;
	while (argv[i++])
	{
		j = i;
		while (++j <= s->size)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j])
				&& ft_isdigit(argv[j][0]) && argv[j][0] != '-'
					&& ft_isdigit(argv[i][0]) && argv[i][0] != '-')
				ft_exit(s, "Error: Duplicate Arguments\n", -1);
		if ((!ft_isdigit(argv[i][0] && (argv[i][0] != '-' || argv[i][1] == 0)))
			|| ft_is_overflow(argv[i]))
			ft_exit(s, "Error: Argument is not an integer\n", -1);
		j = 0;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				ft_exit(s, "Error: Argument is not an integer\n", -1);
		s->a.stack[i - 1] = ft_atoi(argv[i]);
	}
	ft_index(s, &s->a);
}
