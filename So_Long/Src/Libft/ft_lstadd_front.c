/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:40:43 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/17 13:28:08 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*element;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		element = new;
		element->next = *lst;
		*lst = element;
	}
}
