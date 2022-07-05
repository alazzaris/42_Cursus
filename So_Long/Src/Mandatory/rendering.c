/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:42:30 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 13:29:53 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	draw_img_block(t_long *game, char c, int x, int y)
{
	int		w;
	int		h;
	void	*img;
	char	*file;

	if (c == '0')
		file = ft_strdup(BG_BLOCK);
	if (c == 'P')
		file = ft_strdup(PLAYER_BLOCK);
	if (c == '1')
		file = ft_strdup(WALL_BLOCK);
	if (c == 'C')
		file = ft_strdup(KIT_BLOCK);
	if (c == 'E' && game->n_kits != 0)
		file = ft_strdup(EXIT_CLOSE_BLOCK);
	if (c == 'E' && game->n_kits == 0)
		file = ft_strdup(EXIT_OPEN_BLOCK);
	img = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
	w = BLOCK_SIZE * x;
	h = BLOCK_SIZE * y;
	if (!img)
		ft_error_map_not_found();
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, w, h);
	mlx_destroy_image(game->mlx, img);
	free(file);
}

void	draw_map(t_long *game)
{
	int		i;
	int		j;

	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_img_block(game, game->map[i][j], j, i);
	}
}

void	close_game(t_long *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
