/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:02:36 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/16 16:05:33 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s2;

	size = ft_strlen((char *)s1);
	s2 = malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, size);
	s2[size] = '\0';
	return (s2);
}
