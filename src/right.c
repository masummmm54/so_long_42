/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:30:44 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:59:33 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	right_move(t_game *bomb)
{
	int			x;
	int			y;
	int			flag;

	flag = 4;
	x = bomb->player->x_pos;
	y = bomb->player->y_pos;
	if (move_check_right(bomb, x + 1, y) == TRUE)
	{
		bomb->player->player_image->instances[0].x += 32;
		move_actions(bomb, x, y);
		bomb->player->x_pos += 1;
		bomb->player->moves++;
		ft_printf("Player moves = %d\n", bomb->player->moves);
		update_player(bomb, x + 1, y, flag);
	}
	return (TRUE);
}

int	move_check_right(t_game *game, int x, int y)
{
	if (game->lastcolumn - 1 == x)
		return (FALSE);
	if (game->map[y][x] == '1')
		return (FALSE);
	if (game->map[y][x] == 'C')
		put_land(game, x, y);
	return (TRUE);
}
