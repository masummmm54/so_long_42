/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:23:07 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:14:46 by muhakose         ###   ########.fr       */
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
		moves_printer(bomb, "Number of movements == ");
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

void	moves_printer(t_game *bomb, char *msg)
{
	char	*moves;
	char	*moves_counter;

	mlx_delete_image(bomb->mlx, bomb->put_string);
	moves_counter = ft_itoa(bomb->player->moves);
	moves = ft_strjoin(msg, moves_counter);
	bomb->put_string = mlx_put_string(bomb->mlx, moves, 0, 600);
	free(moves);
	free(moves_counter);
}
