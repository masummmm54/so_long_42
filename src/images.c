/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:00:22 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/02 16:47:47 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_door(t_game *game, int m, int n)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png("assets/door.png");
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

void	put_land(t_game *game, int m, int n)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png("assets/land.png");
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

void	put_wall(t_game *game, int m, int n)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png("assets/outerwall.png");
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

void	put_collactable(t_game *game, int m, int n)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png("assets/galp.png");
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

void	put_monster(t_game *game, int m, int n)
{
	mlx_texture_t	*png;
	mlx_image_t		*img;
	int				x;
	int				y;

	x = m * 32;
	y = n * 32;
	png = mlx_load_png("assets/canavar.png");
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
