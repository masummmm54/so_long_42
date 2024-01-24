/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:32:03 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 13:39:00 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	size_for_malloc(t_game *bomb)
{
	int		size;
	int		fd;
	char	*line;

	size = 0;
	fd = open(bomb->map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		size++;
	}
	free(line);
	close(fd);
	return (size + 1);
}

void	find_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x + 1])
		{
			if (game->map[y][x] == 'P')
			{
				game->player->x_pos = x;
				game->player->y_pos = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	free_visited(char **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	directions_init(int directions[4][2])
{
	directions[0][0] = -1;
	directions[0][1] = 0;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
}

void	check_arg(char *file_name)
{
	int	len;
	int	fd;

	len = ft_strlen(file_name);
	if (len > 4 && (ft_strncmp(file_name + len - 4, ".ber", 4) == 0))
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			perror("Open");
			exit (EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("Error. Map should be '.ber' file", 2);
		exit (EXIT_FAILURE);
	}
	close(fd);
}
