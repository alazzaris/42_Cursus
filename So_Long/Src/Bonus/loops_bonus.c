/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:01:43 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 01:03:50 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	animate_kit(int frames, t_long *game)
{
	if (frames % 500 == 0)
	{
		if (game->k_i_direction)
		{
			if (game->k_i == 6)
			{
				game->k_i--;
				game->k_i_direction = 0;
			}
			else
				game->k_i++;
		}
		else
		{
			if (game->k_i == 0)
			{
				game->k_i++;
				game->k_i_direction = 1;
			}
			else
				game->k_i--;
		}
		draw_map(game);
		draw_boss_block(game);
	}
}

void	animate_boss(int frames, t_long *game)
{
	if (game->boss_exist && frames % 1000 == 0)
	{
		if (game->boss_xpm_index_direction)
		{
			if (game->boss_xpm_index == 5)
			{
				game->boss_xpm_index--;
				game->boss_xpm_index_direction = 0;
			}
			else
				game->boss_xpm_index++;
		}
		else
		{
			if (game->boss_xpm_index == 0)
			{
				game->boss_xpm_index++;
				game->boss_xpm_index_direction = 1;
			}
			else
				game->boss_xpm_index--;
		}
		draw_boss_block(game);
	}
}

int	loops(t_long *game)
{
	static int	frames = 0;
	static int	rand = 1;

	animate_kit(frames, game);
	if (game->game)
	{
		animate_boss(frames, game);
		if (game->boss_exist && game->game && frames % 1000 == 0)
		{
			if (rand % 5 == 0)
				move_boss_hook(game, KEY_ARROW_UP);
			if (rand % 5 == 1)
				move_boss_hook(game, KEY_ARROW_DOWN);
			if (rand % 5 == 2)
				move_boss_hook(game, KEY_ARROW_LEFT);
			if (rand % 5 == 3)
				move_boss_hook(game, KEY_ARROW_RIGHT);
			if (game->b_x == game->p_x && game->b_y == game->p_y)
				close_game(game);
		}
		frames++;
		rand *= 13;
	}
	return (0);
}

int	create_text(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
