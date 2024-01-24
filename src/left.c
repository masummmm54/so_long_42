/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:30:20 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/02 18:49:15 by muhakose         ###   ########.fr       */
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
		ft_printf("Player moves = %d\n", bomb->player->moves);
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
		endgame(bomb);
	if (bomb->map[y][x] == 'C')
	{
		bomb->collactable--;
		bomb->map[y][x] = '0';
	}
}
