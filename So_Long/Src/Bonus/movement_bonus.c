/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:35:27 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 14:48:15 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	can_move(t_long *game, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == KEY_UP)
		i = -1;
	if (direction == KEY_DOWN)
		i = 1;
	if (direction == KEY_LEFT)
		j = -1;
	if (direction == KEY_RIGHT)
		j = 1;
	if (game->map[game->p_y + i][game->p_x + j] == '1')
		return (0);
	if (game->map[game->p_y + i][game->p_x + j] == 'E')
		if (game->n_kits)
			return (0);
	game->map[game->p_y][game->p_x] = '0';
	game->p_y += i;
	game->p_x += j;
	return (1);
}

void	move_player(t_long *game)
{
	if (game->map[game->p_y][game->p_x] == 'C')
		game->n_kits--;
	if (game->map[game->p_y][game->p_x] == 'E')
	{
		if (game->n_kits == 0)
			close_game(game);
	}
	game->map[game->p_y][game->p_x] = 'P';
	if (game->game)
	{
		game->count_move++;
		ft_putstr_fd("Moves : ", 1);
		ft_putnbr_fd(game->count_move, 1);
		ft_putchar_fd('\n', 1);
		draw_map(game);
	}
}

void	move_boss(t_long *game, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == KEY_ARROW_UP)
		i = -1;
	if (direction == KEY_ARROW_DOWN)
		i = 1;
	if (direction == KEY_ARROW_LEFT)
		j = -1;
	if (direction == KEY_ARROW_RIGHT)
		j = 1;
	game->map[game->b_y][game->b_x] = '0';
	game->b_y += i;
	game->b_x += j;
}

int	can_move_boss(t_long *game, int direction)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == KEY_ARROW_UP)
		i = -1;
	if (direction == KEY_ARROW_DOWN)
		i = 1;
	if (direction == KEY_ARROW_LEFT)
		j = -1;
	if (direction == KEY_ARROW_RIGHT)
		j = 1;
	if (game->map[game->b_y + i][game->b_x + j] == '1')
		return (0);
	if (game->map[game->b_y + i][game->b_x + j] == 'C')
		return (0);
	if (game->map[game->b_y + i][game->b_x + j] == 'E')
		return (0);
	return (1);
}
