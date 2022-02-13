/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:04:38 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/17 11:01:16 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	j;
	size_t	i;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		substr = (char *)malloc(ft_strlen(s) + 1);
	else
		substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < ft_strlen(s) && j < len)
	{
		substr[j++] = s[i++];
	}
	substr[j] = '\0';
	return (substr);
}
