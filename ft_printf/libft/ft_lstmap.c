/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:05:49 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/16 18:14:50 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*element;

	if (lst == NULL)
		return (NULL);
	map = NULL;
	while (lst != NULL)
	{
		element = ft_lstnew((*f)(lst->content));
		if (element == NULL)
			ft_lstclear(&element, (*del));
		else
			ft_lstadd_back(&map, element);
		lst = lst->next;
	}
	return (map);
}
