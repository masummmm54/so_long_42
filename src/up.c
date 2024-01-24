/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:23:07 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/02 18:47:43 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	up_move(t_game *bomb)
{
	int			x;
	int			y;
	int			flag;

	flag = 2;
	x = bomb->player->x_pos;
	y = bomb->player->y_pos;
	if (move_check_up(bomb, x, y - 1) == TRUE)
	{
		bomb->player->player_image->instances[0].y -= 32;
		move_actions(bomb, x, y);
		bomb->player->y_pos -= 1;
		bomb->player->moves++;
		ft_printf("Player moves = %d\n", bomb->player->moves);
		update_player(bomb, x, y - 1, flag);
	}
	return (TRUE);
}

int	move_check_up(t_game *game, int x, int y)
{
	if (y == 0)
		return (FALSE);
	if (game->map[y][x] == '1')
		return (FALSE);
	if (game->map[y][x] == 'C')
		put_land(game, x, y);
	return (TRUE);
}
