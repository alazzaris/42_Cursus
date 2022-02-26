/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:18:43 by alazzari          #+#    #+#             */
/*   Updated: 2022/02/25 16:21:45 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free(t_stack **s, t_info **info)
{
	t_stack	*temp;

	if (*s)
		(*s)->previous->next = NULL;
	while (*s)
	{
		temp = *s;
		*s = (*s)->next;
		free(temp);
		temp = NULL;
	}
	free(*info);
	*info = NULL;
	return (0);
}
