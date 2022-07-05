/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:42:30 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 14:48:56 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static char	*get_file(char *start, int index)
{
	char	*file;
	char	*temp1;
	char	*temp2;

	temp1 = ft_itoa(index);
	temp2 = ft_strjoin(start, temp1);
	file = ft_strjoin(temp2, ".xpm");
	free(temp1);
	free(temp2);
	return (file);
}

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
		file = get_file(KIT_BLOCK, game->k_i);
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
	char	*str;
	int		c;

	i = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			draw_img_block(game, game->map[i][j], j, i);
	}
	str = ft_itoa(game->count_move);
	c = create_text(1, 0, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 0, 0, c, "Moves : ");
	mlx_string_put(game->mlx, game->mlx_win, 100, 0, c, str);
	free(str);
}

void	draw_boss_block(t_long *game)
{
	int		w;
	int		h;
	void	*img;
	char	*file;

	if (game->boss_exist)
	{
		file = get_file(BOSS_BLOCK, game->boss_xpm_index);
		img = mlx_xpm_file_to_image(game->mlx, file, &w, &h);
		if (!img)
			ft_error_map_not_found();
		w = BLOCK_SIZE * game->b_x;
		h = BLOCK_SIZE * game->b_y;
		mlx_put_image_to_window(game->mlx, game->mlx_win, img, w, h);
		mlx_destroy_image(game->mlx, img);
		free(file);
	}
}

void	close_game(t_long *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
