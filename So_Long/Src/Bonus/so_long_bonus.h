/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:58:17 by alazzari          #+#    #+#             */
/*   Updated: 2022/03/26 15:18:41 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

# include "./get_next_line_bonus.h"
# include "../Libft/libft.h"

# define BLOCK_SIZE 64
# define BUFFER_SIZE 1

# define PLAYER_BLOCK "Xpm/player-0.xpm"
# define WALL_BLOCK "Xpm/water-1.xpm"
# define KIT_BLOCK "Xpm/k-"
# define BG_BLOCK "Xpm/snow.xpm"
# define EXIT_OPEN_BLOCK "Xpm/exit-1.xpm"
# define EXIT_CLOSE_BLOCK "Xpm/exit-0.xpm"
# define BOSS_BLOCK "Xpm/b-"

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53

# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

# define ERROR_MAP_NOT_FOUND 1
# define ERROR_MAP_NOT_VALID 2
# define ERROR_MAP_WIDTH 3
# define ERROR_MAP_BORDER 4
# define ERROR_MAP_PLAYER 5
# define ERROR_MAP_EXIT 6
# define ERROR_MAP_KITS 7
# define ERROR_MAP_FOUND_FORBIDDEN_OBJECT 8
# define ERROR_MAP_NOT_BER_EXTENTION 9
# define ERROR_GAME_IS_NULL 100

typedef struct s_long
{
	char	**map;
	int		game;
	int		k_i;
	int		k_i_direction;
	int		boss_xpm_index;
	int		boss_xpm_index_direction;
	int		boss_exist;
	int		b_x;
	int		b_y;
	int		count_move;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		n_kits;
	void	*mlx;
	void	*mlx_win;
}	t_long;

int		ft_map(t_long *game);
int		ft_map_width(t_long *game);
int		ft_map_border(t_long *game);
int		ft_map_name(char *map_file);

int		ft_map_player(t_long *game);
int		ft_map_exit(t_long *game);
int		ft_map_kits(t_long *game);
int		ft_map_other_chars(t_long *game);

void	ft_error_map_border(void);
void	ft_error_map_player(void);
void	ft_error_map_exit(void);
void	ft_error_map_found_forbidden_object(void);

void	ft_error_map_not_found(void);
void	ft_error_map_not_valid(void);
void	ft_error_map_not_ber_extention(void);
void	ft_error_game_is_null(void);
void	ft_error_map_width(void);

int		movehook(t_long *game, int keycode);
int		hooks(int keycode, t_long *game);
int		destroy_hook(t_long *game);
int		move_boss_hook(t_long *game, int keycode);

int		init_map(char *map_path, t_long *game);
t_long	*init_game(char *map_path);
int		free_game(t_long **game);
int		count_height(int fd);
void	set_init_boss(t_long *game);

int		can_move(t_long *game, int direction);
void	move_player(t_long *game);
void	move_boss(t_long *game, int direction);
int		can_move_boss(t_long *game, int direction);

void	draw_img_block(t_long *game, char c, int x, int y);
void	draw_map(t_long *game);
void	draw_boss_block(t_long *game);
void	close_game(t_long *game);

void	animate_kit(int frames, t_long *game);
void	animate_boss(int frames, t_long *game);
int		loops(t_long *game);
int		create_text(int t, int r, int g, int b);

#endif