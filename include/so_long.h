/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:34:36 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:32:18 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include "MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define WIDTH 2200
# define HEIGHT 1200

typedef struct s_player
{
	mlx_image_t	*player_image;
	char		*player_png_path;
	int			x_pos;
	int			y_pos;
	int			moves;
}	t_player;

typedef struct s_monster
{
	mlx_image_t	*monster_image;
	int			monster_x_pos;
	int			monster_y_pos;
	int			flag;
}	t_monster;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			*map_path;
	int				lastrow;
	int				lastcolumn;
	int				collactable;
	int				monster_number;
	t_player		*player;
	t_monster		**monster;
	mlx_image_t		*put_string;
}	t_game;

enum e_keycode
{
	KEY_UP = 87,
	KEY_DOWN = 83,
	KEY_LEFT = 65,
	KEY_RIGHT = 68,
	RESET = 15,
	ESC = 256
};

void	put_image(char s, t_game *bomb, int x, int y);
void	put_door(t_game *game, int x, int y);
void	put_land(t_game *game, int x, int y);
void	put_wall(t_game *game, int x, int y);
void	put_monster(t_game *game, int m, int n);
void	put_innerwall(t_game *game, int m, int n);
void	put_player(t_game *bomb, int m, int n);
void	put_collactable(t_game *game, int m, int n);
void	init_map(t_game *bomb, char **map);
int		size_for_malloc(t_game *bomb);
char	**get_me_visited(t_game *game);

void	check_map(t_game *bomberman);
void	check_arg(char *file_name);
int		is_there_path(t_game *game);
void	find_player_pos(t_game *game);
void	is_valid_map(t_game *bomberman, char **map);
int		is_rectanguler_map(char **map);
int		is_outside_wall(t_game *bomberman);
int		is_there_door_and_player(t_game *game);
int		can_collect_all_and_exit(t_game *game, char **grid,
			int start_row, int start_col);
bool	is_valid_move(t_game *game, char **visited, int row, int col);
void	dfs(t_game *game, char **visited, int row, int col);
void	directions_init(int directions[4][2]);
int		only_one(t_game	*bomb);

int		up_move(t_game *bomb);
int		down_move(t_game *bomb);
int		right_move(t_game *bomb);
int		left_move(t_game *bomb);

int		move_check_up(t_game *game, int x, int y);
int		move_check_down(t_game *game, int x, int y);
int		move_check_right(t_game *game, int x, int y);
int		move_check_left(t_game *game, int x, int y);

void	move_actions(t_game *bomb, int x, int y);
void	endgame(t_game *game);
void	endgame_bonus(t_game *game, char *msg);
void	player_image(t_game *game, int flag);
void	update_player(t_game *game, int x, int y, int flag);

void	array_free(char **s);
void	free_all(t_game *game);
void	free_visited(char **visited, int rows);
void	check_error(t_game *game, char *s, char **map);

void	get_monsters(t_game *game, int m, int n);
void	put_monster_bonus(t_game *game, int m, int n, int monster_number);
void	monster_move(void *param);
void	update_monster_positions(t_game *game);
int		monster_right(t_game *game, int i);
int		monster_left(t_game *game, int i);
int		monster_up(t_game *game, int i);
int		monster_down(t_game *game, int i);
int		rand_flag(void);
void	moves_printer(t_game *bomb, char *msg);
void	you_died(t_game *game, int x, int y);

#endif