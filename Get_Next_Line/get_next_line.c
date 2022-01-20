/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:49:08 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/20 17:39:35 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	ft_free(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		str = NULL;
	}
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	int				read_result;
	char			*temp;
	static char		*store;

	read_result = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	temp = NULL;
	while (read_result > 0)
	{
		read_result = ft_read(fd, buffer);
		if (read_result < 0)
			return (-1);
		store = ft_store(store, buffer);
		if (ft_newline )
	}  
	
}
