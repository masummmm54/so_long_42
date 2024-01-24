/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:21:16 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/16 15:25:00 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_there_path(t_game *game)
{
	int	pos_x;
	int	pos_y;

	find_player_pos(game);
	pos_x = game->player->x_pos;
	pos_y = game->player->y_pos;
	if (can_collect_all_and_exit(game, game->map, pos_y, pos_x) == FALSE)
		return (FALSE);
	return (TRUE);
}

bool	is_valid_move(t_game *game, char **visited, int row, int col)
{
	return (row >= 0 && col >= 0 && row < game->lastrow
		&& col < game->lastcolumn && visited[row][col] == 'f'
		&& game->map[row][col] != '1');
}

void	dfs(t_game *game, char **visited, int row, int col)
{
	int	directions[4][2];
	int	i;
	int	newrow;
	int	newcol;

	visited[row][col] = 't';
	directions_init(directions);
	i = 0;
	while (i < 4)
	{
		newrow = row + directions[i][0];
		newcol = col + directions[i][1];
		i++;
		if (is_valid_move(game, visited, newrow, newcol))
		{
			dfs(game, visited, newrow, newcol);
		}
	}
}

int	can_collect_all_and_exit(t_game *game, char **grid,
	int start_row, int start_col)
{
	char	**visited;
	int		j;
	int		i;

	visited = get_me_visited(game);
	dfs(game, visited, start_row, start_col);
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if ((grid[i][j] == 'C' && visited[i][j] == 'f')
				|| ((grid[i][j]) == 'E' && visited[i][j] == 'f'))
			{
				free_visited(visited, game->lastrow + 1);
				return (FALSE);
			}
			j++;
		}
		i++;
	}
	array_free(visited);
	return (TRUE);
}

char	**get_me_visited(t_game *game)
{
	char	**visited;
	int		i;
	int		j;

	i = 0;
	visited = malloc (sizeof(char **) * (game->lastrow + 2));
	while (game->map[i])
	{
		j = 0;
		visited[i] = malloc (sizeof(char) * (game->lastcolumn + 1));
		while (game->map[i][j])
		{
			visited[i][j] = 'f';
			j++;
		}
		visited[i][j] = '\0';
		i++;
	}
	visited[i] = NULL;
	return (visited);
}
