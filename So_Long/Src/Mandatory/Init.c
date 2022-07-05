/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:41:41 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 14:41:41 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	init_map(char *map_path, t_long *game)
{
	int	height;
	int	fd;
	int	i;

	height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error_map_not_found();
	height = count_height(fd);
	if (height == 0)
		ft_error_map_not_valid();
	game->map = malloc(sizeof(char *) * (height));
	close(fd);
	i = -1;
	fd = open(map_path, O_RDONLY);
	while (++i < height && game->map)
		game->map[i] = get_next_line(fd);
	close(fd);
	game->height = height;
	if (game->map)
		game->width = ft_strlen(game->map[i - 1]);
	if (!game->map || !ft_map(game))
		return (free_game(&game));
	return (1);
}

t_long	*init_game(char *map_path)
{
	t_long	*game;

	if (!ft_map_name(map_path))
		ft_error_map_not_ber_extention();
	game = malloc(sizeof(t_long));
	if (!game)
		ft_error_game_is_null();
	game->count_move = 0;
	game->game = 1;
	if (!init_map(map_path, game))
		game = NULL;
	return (game);
}

int	free_game(t_long **game)
{
	int	i;

	i = -1;
	if (!game || !(*game))
		return (0);
	while (++i < (*game)->height)
		free((*game)->map[i]);
	free((*game)->map);
	free(*game);
	*game = NULL;
	return (0);
}

int	count_height(int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (i);
}
