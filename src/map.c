/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:15:25 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:38:52 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_game *bomb, char **map)
{
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (map[x])
	{
		i = 0;
		while (map[x][i] != 0)
		{
			put_image(map[x][i], bomb, i, x);
			i++;
		}
		x++;
	}
	put_player(bomb, bomb->player->x_pos, bomb->player->y_pos);
}

void	put_image(char s, t_game *bomb, int x, int y)
{
	if (s == '0')
		put_land(bomb, x, y);
	else if (s == '1' && (x == 0 || y == 0 || y == bomb->lastrow
			|| x == bomb->lastcolumn - 1))
		put_wall(bomb, x, y);
	else if (s == '1')
		put_innerwall(bomb, x, y);
	else if (s == 'E')
		put_door(bomb, x, y);
	else if (s == 'C')
	{
		put_land(bomb, x, y);
		put_collactable(bomb, x, y);
	}
	else if (s == 'N')
		put_monster(bomb, x, y);
	else if (s == 'P')
	{
		bomb->player->x_pos = x;
		bomb->player->y_pos = y;
		put_land(bomb, x, y);
	}
}

int	is_there_door_and_player(t_game *game)
{
	int	y;
	int	x;
	int	count_p;
	int	count_e;

	count_e = 0;
	count_p = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				count_p++;
			if (game->map[y][x] == 'E')
				count_e++;
			x++;
		}
		y++;
	}
	if (count_e != 1 || count_p != 1)
		return (FALSE);
	return (TRUE);
}
