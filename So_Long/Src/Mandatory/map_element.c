/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:42:35 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 13:28:41 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_map_player(t_long *game)
{
	int	n_player;
	int	i;
	int	j;

	n_player = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				n_player++;
				game->p_x = j;
				game->p_y = i;
			}
		}
	}
	if (n_player == 1)
		return (1);
	else
		return (0);
}

int	ft_map_exit(t_long *game)
{
	int	n_exits;
	int	i;
	int	j;

	n_exits = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'E')
				n_exits++;
		}
	}
	if (n_exits >= 1)
		return (1);
	else
		return (0);
}

int	ft_map_kits(t_long *game)
{
	int	n_kits;
	int	i;
	int	j;

	n_kits = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				n_kits++;
		}
	}
	game->n_kits = n_kits;
	if (n_kits > 0)
		return (1);
	else
		return (0);
}

int	ft_map_other_chars(t_long *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (!ft_strchr("EPC01", game->map[i][j]))
				return (0);
		}
	}
	return (1);
}
