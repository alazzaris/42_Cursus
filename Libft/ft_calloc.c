/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:24:02 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/14 09:40:51 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	total = size * count;
	ptr = malloc(total);
	if (!ptr)
		return (0);
	ft_bzero(ptr, total);
	return (ptr);
}
