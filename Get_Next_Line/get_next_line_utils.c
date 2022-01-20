/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:54:17 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/20 14:23:28 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s2;

	size = ft_strlen((char *)s1);
	s2 = malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (NULL);
	while (s2[size])
		s2[size] = s1[size];
		size++;
	s2[size] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len;
	size_t	i;
	char	*s3;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (s3 == NULL)
		return (NULL);
	while (*s1 != '\0')
		s3[i++] = *s1++;
	while (*s2 != '\0')
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}
