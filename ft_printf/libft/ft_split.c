/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:06:20 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/16 15:27:51 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && counter == 0)
		{
			counter = 1;
			i++;
		}
		else if (*str == c)
			counter = 0;
		str++;
	}
	return (i);
}

static char	*ft_dupl(const char *str, int start, int last)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (last - start + 1));
	if (!word || !str)
		return (NULL);
	while (start < last)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_dupl(s, index, i);
			j++;
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
