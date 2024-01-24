/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:30:33 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 14:12:26 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_monsters(t_game *game, int m, int n)
{
	static int	monster_number;

	game->monster[monster_number]->monster_x_pos = m;
	game->monster[monster_number]->monster_y_pos = n;
	game->monster[monster_number]->flag = rand_flag();
	monster_number++;
}

void	put_monster_bonus(t_game *game, int m, int n, int monster_number)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png("assets/canavar.png");
	if (!png)
		return (ft_putendl_fd("Png Error", 2), exit(1));
	img = mlx_texture_to_image(game->mlx, png);
	if (!img)
		return (ft_putendl_fd("Png Error", 2), exit(1));
	if (mlx_image_to_window(game->mlx, img, x, y))
		return (ft_putendl_fd("Png Error", 2), exit(1));
	mlx_delete_texture(png);
	game->monster[monster_number]->monster_image = img;
}

void	monster_move(void *param)
{
	t_game		*game;
	static int	m;

	game = (t_game *)param;
	m += 1;
	if (m % 32 == 0)
		update_monster_positions(game);
}

void	update_monster_positions(t_game *game)
{
	int			i;

	i = 0;
	while (i < game->monster_number)
	{
		if (game->monster[i]->flag == 1)
		{
			monster_right(game, i);
		}
		if (game->monster[i]->flag == 2)
		{
			monster_up(game, i);
		}
		if (game->monster[i]->flag == 3)
		{
			monster_left(game, i);
		}
		if (game->monster[i]->flag == 4)
		{
			monster_down(game, i);
		}
		i++;
	}
}

int	rand_flag(void)
{
	int	x;

	x = rand();
	if (x % 4 == 0)
		return (1);
	else if (x % 4 == 1)
		return (2);
	else if (x % 4 == 2)
		return (3);
	else
		return (4);
}
