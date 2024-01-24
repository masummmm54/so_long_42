/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:55:13 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:31:23 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	monster_right(t_game *game, int i)
{
	int	x;
	int	y;

	x = game->monster[i]->monster_x_pos;
	y = game->monster[i]->monster_y_pos;
	if (game->map[y][x + 1] != '1')
	{
		you_died(game, x, y);
		game->monster[i]->monster_x_pos += 1;
		x += 1;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'Z';
		else if (game->map[y][x] == 'E')
			game->map[y][x] = 'B';
		else
			game->map[y][x] = 'N';
		mlx_delete_image(game->mlx, game->monster[i]->monster_image);
		put_monster_bonus(game, x, y, i);
		return (TRUE);
	}
	game->monster[i]->flag = rand_flag();
	return (FALSE);
}

int	monster_left(t_game *game, int i)
{
	int	x;
	int	y;

	x = game->monster[i]->monster_x_pos;
	y = game->monster[i]->monster_y_pos;
	if (game->map[y][x - 1] != '1')
	{
		you_died(game, x, y);
		x -= 1;
		game->monster[i]->monster_x_pos -= 1;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'Z';
		else if (game->map[y][x] == 'E')
			game->map[y][x] = 'B';
		else
			game->map[y][x] = 'N';
		mlx_delete_image(game->mlx, game->monster[i]->monster_image);
		put_monster_bonus(game, x, y, i);
		return (TRUE);
	}
	game->monster[i]->flag = rand_flag();
	return (FALSE);
}

int	monster_up(t_game *game, int i)
{
	int	x;
	int	y;

	x = game->monster[i]->monster_x_pos;
	y = game->monster[i]->monster_y_pos;
	if (game->map[y - 1][x] != '1')
	{
		you_died(game, x, y);
		game->monster[i]->monster_y_pos -= 1;
		y -= 1;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'Z';
		else if (game->map[y][x] == 'E')
			game->map[y][x] = 'B';
		else
			game->map[y][x] = 'N';
		mlx_delete_image(game->mlx, game->monster[i]->monster_image);
		put_monster_bonus(game, x, y, i);
		return (TRUE);
	}
	game->monster[i]->flag = rand_flag();
	return (FALSE);
}

int	monster_down(t_game *game, int i)
{
	int	x;
	int	y;

	x = game->monster[i]->monster_x_pos;
	y = game->monster[i]->monster_y_pos;
	if (game->map[y + 1][x] != '1')
	{
		you_died(game, x, y);
		y += 1;
		if (game->map[y][x] == 'C')
			game->map[y][x] = 'Z';
		else if (game->map[y][x] == 'E')
			game->map[y][x] = 'B';
		else
			game->map[y][x] = 'N';
		game->monster[i]->monster_y_pos += 1;
		mlx_delete_image(game->mlx, game->monster[i]->monster_image);
		put_monster_bonus(game, x, y, i);
		return (TRUE);
	}
	game->monster[i]->flag = rand_flag();
	return (FALSE);
}

void	you_died(t_game *game, int x, int y)
{
	if (game->player->x_pos == x && game->player->y_pos == y)
	{
		update_player(game, x, y, 1);
		usleep(500000);
		update_player(game, x, y, 2);
		usleep(500000);
		update_player(game, x, y, 3);
		usleep(500000);
		endgame_bonus(game, "You died.");
	}
	if (game->map[y][x] == 'Z')
		game->map[y][x] = 'C';
	else if (game->map[y][x] == 'B')
		game->map[y][x] = 'E';
	else
		game->map[y][x] = '0';
}
