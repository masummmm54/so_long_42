/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:18:19 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/02 16:46:45 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_player(t_game *bomb, int m, int n)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png(bomb->player->player_png_path);
	if (!png)
		return (ft_putendl_fd("Png Error", 2), exit(1));
	img = mlx_texture_to_image(bomb->mlx, png);
	if (!img)
	{
		ft_putendl_fd("Image Error", 2);
		exit(1);
	}
	if (mlx_image_to_window(bomb->mlx, img, x, y))
	{
		ft_putendl_fd("Image Error", 2);
		exit(1);
	}
	mlx_delete_texture(png);
	bomb->player->player_image = img;
}

void	put_innerwall(t_game *game, int m, int n)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png("assets/regularwall.png");
	if (!png)
	{
		ft_putendl_fd("Png Error", 2);
		exit(1);
	}
	img = mlx_texture_to_image(game->mlx, png);
	if (!game->mlx)
	{
		ft_putendl_fd("Image Error", 2);
		exit(1);
	}
	if (mlx_image_to_window(game->mlx, img, x, y))
	{
		ft_putendl_fd("Image Error", 2);
		exit(1);
	}
	mlx_delete_texture(png);
}
