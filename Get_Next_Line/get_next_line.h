/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:49:26 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/20 15:35:13 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_SIZE 4096

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8

# endif

char			*get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(const char *s, size_t len);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char *s1, const char *s2);
static size_t	ft_strlen(const char *s1);

#endif
