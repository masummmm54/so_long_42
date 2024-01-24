/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:30:20 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:08:01 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	left_move(t_game *bomb)
{
	int			x;
	int			y;
	int			flag;

	flag = 3;
	x = bomb->player->x_pos;
	y = bomb->player->y_pos;
	if (move_check_left(bomb, x - 1, y) == TRUE)
	{
		bomb->player->player_image->instances[0].x -= 32;
		move_actions(bomb, x, y);
		bomb->player->x_pos -= 1;
		bomb->player->moves++;
		moves_printer(bomb, "Number of movements == ");
		update_player(bomb, x - 1, y, flag);
	}
	return (TRUE);
}

int	move_check_left(t_game *game, int x, int y)
{
	if (x == 0)
		return (FALSE);
	if (game->map[y][x] == '1')
		return (FALSE);
	if (game->map[y][x] == 'C')
		put_land(game, x, y);
	return (TRUE);
}

void	move_actions(t_game *bomb, int x, int y)
{
	if (bomb->map[y][x] == 'E' && bomb->collactable == 0)
		endgame_bonus(bomb, "You have finished the game.");
	if (bomb->map[y][x] == 'N')
		you_died(bomb, x, y);
	if (bomb->map[y][x] == 'C')
	{
		bomb->collactable--;
		bomb->map[y][x] = '0';
	}
}
