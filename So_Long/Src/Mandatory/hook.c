/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:42:15 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 01:49:56 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	movehook(t_long *game, int keycode)
{
	if (!can_move(game, keycode))
		return (0);
	move_player(game);
	return (1);
}

int	hooks(int keycode, t_long *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if ((keycode == KEY_DOWN || keycode == KEY_UP) && game->game)
		movehook(game, keycode);
	if ((keycode == KEY_LEFT || keycode == KEY_RIGHT) && game->game)
		movehook(game, keycode);
	return (0);
}

int	destroy_hook(t_long *game)
{
	close_game(game);
	return (0);
}
