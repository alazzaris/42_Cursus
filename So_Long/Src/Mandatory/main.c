/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:42:24 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 00:44:39 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_long	*game;
	int		w;
	int		h;

	if (argc <= 1)
		ft_error_map_not_found();
	game = init_game(argv[1]);
	if (!game || !game->map)
		ft_error_game_is_null();
	w = game->width * BLOCK_SIZE;
	h = game->height * BLOCK_SIZE;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, w, h, "Chopper's Adventure");
	draw_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, hooks, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, destroy_hook, game);
	mlx_loop(game->mlx);
	free(game->mlx_win);
	free(game->mlx);
	free(game);
	return (0);
}
