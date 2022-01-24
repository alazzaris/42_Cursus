/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:04:24 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/13 08:56:31 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	index;
	char			*last;

	last = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			last = (char *)&s[index];
		index++;
	}
	if ((char)c == s[index])
		return ((char *)&s[index]);
	return (last);
}
