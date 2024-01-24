/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:02:46 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/02 20:25:19 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_game *game)
{
	array_free(game->map);
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
