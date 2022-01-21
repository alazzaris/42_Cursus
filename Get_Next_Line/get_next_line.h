/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:49:26 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/21 19:13:26 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *store);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *store, char *buffer);
size_t	ft_strlen(char *s);
char	*ft_newline(char *store);
char	*ft_final_line(char *store);

#endif
