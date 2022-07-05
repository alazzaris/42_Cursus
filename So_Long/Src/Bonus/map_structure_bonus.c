/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structure_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:36:15 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 14:42:49 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	ft_map_name(char *map_file)
{
	char	*s;

	if (!map_file)
		return (0);
	s = ft_strrchr(map_file, '.');
	if (!s)
		return (0);
	if (ft_strlen(map_file) < 5)
		return (0);
	if (ft_strncmp(s, ".ber", 5))
		return (0);
	return (1);
}

int	ft_map_border(t_long *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		if (i == 0 || i == game->height -1)
		{
			while (++j < game->width)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
		}
		if (game->map[i][0] != '1')
			return (0);
		if (game->map[i][game->width - 1] != '1')
			return (0);
	}
	return (1);
}

int	ft_map_width(t_long *game)
{
	int	i;

	i = -1;
	if (!game || !game->map)
		return (0);
	while (++i < game->height - 1)
	{
		if (ft_strlen(game->map[i]) - 1 != (size_t)game->width)
			return (0);
	}
	return (1);
}

int	ft_map(t_long *game)
{
	if (!game)
		ft_error_game_is_null();
	if (!ft_map_width(game))
		ft_error_map_width();
	if (!ft_map_border(game))
		ft_error_map_border();
	if (!ft_map_player(game))
		ft_error_map_player();
	if (!ft_map_exit(game))
		ft_error_map_exit();
	if (!ft_map_kits(game))
		return (0);
	if (!ft_map_other_chars(game))
		ft_error_map_found_forbidden_object();
	return (1);
}
