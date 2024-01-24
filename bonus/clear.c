/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:02:46 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/12 11:55:45 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	array_free(game->map);
	while (i < game->monster_number)
	{
		free(game->monster[i]);
		i++;
	}
	free(game->monster);
	free(game->player);
	free(game);
}

void	array_free(char **s)
{
	int	x;

	x = 0;
	while (s[x] != NULL)
	{
		free(s[x]);
		x++;
	}
	free(s);
}

void	check_error(t_game *game, char *s, char **map)
{
	ft_putendl_fd(s, 2);
	array_free(game->map);
	array_free(map);
	exit(EXIT_FAILURE);
}
