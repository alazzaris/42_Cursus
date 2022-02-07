/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:07:18 by alazzari          #+#    #+#             */
/*   Updated: 2022/01/31 16:59:03 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char(char c, char *str)
{
	int	i;
	
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	int		j = 0;
	char	res[255];

	while (i < 255)
		res[i++] = 0;
	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (ft_char(argv[1][i], argv[2]) && !ft_char(argv[1][i], res))
			{
				res[j] = argv[1][i];
				j++;
			}
			i++;
		}
	}
	i = 0;
	while (res[i])
	{
		write(1, "\n", 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}