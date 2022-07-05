/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:22:34 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/23 16:36:10 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_newline(char *store)
{
	int		i;
	char	*str;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		str[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		str[i] = store[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_final_line(char *store)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_len(store) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (store[i])
		str[j++] = store[i++];
	str[j] = '\0';
	free(store);
	return (str);
}

char	*ft_read(int fd, char *store)
{
	char	*buffer;
	int		read_result;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_result = 1;
	while (!ft_chr(store, '\n') && read_result)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_result] = '\0';
		store = ft_join(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	store = ft_read(fd, store);
	if (!store)
		return (NULL);
	line = ft_newline(store);
	store = ft_final_line(store);
	return (line);
}
