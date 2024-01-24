/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:59:37 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:13:15 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hook(mlx_key_data_t keys, void *game)
{
	t_game	*bomb;
	int		keycode;

	bomb = (t_game *)game;
	keycode = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (keycode == ESC)
		{
			mlx_close_window(bomb->mlx);
			ft_putendl_fd("Game Closed", 1);
			free_all(bomb);
			exit(EXIT_SUCCESS);
		}
		else if (keycode == KEY_UP)
			up_move(bomb);
		else if (keycode == KEY_DOWN)
			down_move(bomb);
		else if (keycode == KEY_LEFT)
			left_move(bomb);
		else if (keycode == KEY_RIGHT)
			right_move(bomb);
	}
}

void	init_game(t_game *bomb)
{
	int	i;

	i = 0;
	bomb->mlx = mlx_init(WIDTH, HEIGHT, "BOMBERMAN", true);
	if (!(bomb->mlx))
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	bomb->player->moves = 0;
	bomb->player->player_png_path = "assets/player.png";
	bomb->monster = malloc (sizeof(t_monster *) * bomb->monster_number);
	while (i < bomb->monster_number)
	{
		bomb->monster[i] = malloc (sizeof(t_monster));
		i++;
	}
}

void	checkleaks(void)
{
	system("leaks so_long");
}

int	main2(int ac, char **av)
{
	t_game	*bomberman;

	if (ac != 2)
		return (perror("Wrong argument count!"), 1);
	check_arg(av[1]);
	bomberman = malloc (sizeof(t_game));
	if (bomberman == NULL)
		exit(EXIT_FAILURE);
	bomberman->player = malloc(sizeof(t_player));
	if (bomberman->player == NULL)
		exit(EXIT_FAILURE);
	bomberman->map_path = av[1];
	check_map(bomberman);
	init_game(bomberman);
	init_map(bomberman, bomberman->map);
	mlx_key_hook(bomberman->mlx, ft_hook, bomberman);
	mlx_loop_hook(bomberman->mlx, monster_move, bomberman);
	mlx_loop(bomberman->mlx);
	free_all(bomberman);
	mlx_terminate(bomberman->mlx);
	ft_putendl_fd("Game Closed", 1);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	atexit(&checkleaks);
	main2(ac, av);
	system("leaks so_long");
	return (0);
}
