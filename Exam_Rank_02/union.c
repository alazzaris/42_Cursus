/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:59:25 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/31 17:23:15 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_not_seen_before(char *s, int max_pos, char c)
{
	int	i;

	i = -1;
	while (i < max_pos)
	{
		if (s[i] == c)
			return (0);
	}
	return (1);
}

void	ft_union(char *str1, char *str2)
{
	int	i;
	int	j;

	i = -1;
	while (str1[++i])
		if (ft_not_seen_before(str1, i, str1[i]))
			write(1, &str1[i], 1);
	j = -1;
	while (str2[++j])
		if (ft_not_seen_before(str1, i, str1[i])
			&& ft_not_seen_before(str2, j, str2[j]))
			write(1, &str2[j], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
