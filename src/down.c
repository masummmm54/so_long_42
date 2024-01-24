/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:23:07 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/02 18:50:43 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	down_move(t_game *bomb)
{
	int			x;
	int			y;
	int			flag;

	flag = 1;
	x = bomb->player->x_pos;
	y = bomb->player->y_pos;
	if (move_check_down(bomb, x, y + 1) == TRUE)
	{
		bomb->player->player_image->instances[0].y += 32;
		move_actions(bomb, x, y);
		bomb->player->y_pos += 1;
		bomb->player->moves++;
		ft_printf("Player moves = %d\n", bomb->player->moves);
		update_player(bomb, x, y + 1, flag);
	}
	return (TRUE);
}

int	move_check_down(t_game *game, int x, int y)
{
	if (game->lastrow == y)
		return (FALSE);
	if (game->map[y][x] == '1')
		return (FALSE);
	if (game->map[y][x] == 'C')
		put_land(game, x, y);
	return (TRUE);
}

void	endgame(t_game *game)
{
	game->player->player_image->instances[0].y += 32;
	usleep(50000);
	ft_printf("You have finished the game\n");
	free_all(game);
	exit (EXIT_SUCCESS);
}

void	update_player(t_game *game, int x, int y, int flag)
{
	mlx_delete_image(game->mlx, game->player->player_image);
	player_image(game, flag);
	put_player(game, x, y);
}

void	player_image(t_game *game, int flag)
{
	if (flag == 1)
		game->player->player_png_path = "assets/move_down.png";
	else if (flag == 2)
		game->player->player_png_path = "assets/player_butt.png";
	else if (flag == 3)
		game->player->player_png_path = "assets/left_player.png";
	else if (flag == 4)
		game->player->player_png_path = "assets/right_player.png";
}
