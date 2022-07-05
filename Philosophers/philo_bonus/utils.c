/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:13:06 by alazzari          #+#    #+#             */
/*   Updated: 2022/05/19 16:24:10 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(const char *str, int *i, int *n)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		++*i;
	if (str[*i] == '-')
	{
		*n = -(*n);
		++*i;
		if (!ft_isdigit(str[*i]))
			return (1);
	}
	if (str[*i] == '+')
	{
		++*i;
		if (!ft_isdigit(str[*i]))
			return (1);
	}
	return (0);
}

int	check_digit(const char *str, int *i)
{
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]))
			return (1);
		++*i;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			n;
	long int	result;

	i = 0;
	n = 1;
	result = 0;
	if (ft_isspace(str, &i, &n))
		return (-1);
	j = i;
	if (check_digit(str, &i))
		return (-1);
	while (str[j] >= '0' && str[j] <= '9')
	{
		result = result * 10 + str[j] - '0';
		j++;
		if (result > 2147483647 || result < -2147483648)
			break ;
	}
	return (result * n);
}
