/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:51:05 by muhakose          #+#    #+#             */
/*   Updated: 2024/01/13 14:33:21 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_game *bomberman)
{
	char	**map;
	int		fd;
	int		i;

	map = (char **)malloc(sizeof(char **) * size_for_malloc(bomberman));
	i = 0;
	fd = open(bomberman->map_path, O_RDONLY);
	map[i] = get_next_line(fd);
	if (map[i] == NULL)
		return (ft_putendl_fd("Error. Empty map!", 2), exit(1));
	while (map[i++])
		map[i] = get_next_line(fd);
	close(fd);
	bomberman->lastcolumn = ft_strlen(map[0]) - 1;
	bomberman->map = malloc(sizeof(char **) * size_for_malloc(bomberman));
	i = -1;
	while (map[++i])
	{
		bomberman->map[i] = malloc (sizeof(char) * bomberman->lastcolumn);
		ft_strncpy(bomberman->map[i], map[i], bomberman->lastcolumn);
		bomberman->map[i][bomberman->lastcolumn] = '\0';
	}
	bomberman->map[i] = NULL;
	bomberman->lastrow = i - 1;
	is_valid_map(bomberman, map);
}

void	is_valid_map(t_game *bomberman, char **map)
{
	if (is_rectanguler_map(map) == FALSE)
		check_error(bomberman, "ERROR. Map is not rectangular!", map);
	if (is_outside_wall(bomberman) == FALSE)
		check_error(bomberman, "ERROR. Map is not surrounded by walls!", map);
	if (only_one(bomberman) == FALSE)
		check_error(bomberman, "ERROR. Map does have invalid character!", map);
	if (is_there_door_and_player(bomberman) == FALSE)
		check_error(bomberman,
			"ERROR. Map does not have a one player or one door!", map);
	if (is_there_path(bomberman) == FALSE)
		check_error(bomberman, "ERROR. Map does not have a solution!", map);
	array_free(map);
}

int	is_outside_wall(t_game *bomberman)
{
	int	x;

	x = 0;
	while (bomberman->map[x])
	{
		if (bomberman->map[x][0] != '1'
			|| bomberman->map[x][bomberman->lastcolumn - 1] != '1')
			return (FALSE);
		x++;
	}
	x = 0;
	while (bomberman->map[0][x + 1])
	{
		if (bomberman->map[0][x] != '1'
			|| bomberman->map[bomberman->lastrow][x] != '1')
			return (FALSE);
		x++;
	}
	return (TRUE);
}

int	is_rectanguler_map(char **map)
{
	int		x;
	size_t	length;

	length = ft_strlen(map[0]);
	x = 0;
	while (map[x + 1])
	{
		if (ft_strlen(map[x]) != length)
			return (FALSE);
		x++;
	}
	if (ft_strlen(map[x]) != length - 1)
		return (FALSE);
	return (TRUE);
}

int	only_one(t_game	*bomb)
{
	int		x;
	char	*s;
	int		count_collactable;

	count_collactable = 0;
	x = -1;
	while (bomb->map[++x])
	{
		s = bomb->map[x];
		while (*s != '\0')
		{
			if (!ft_strchr("EP01C", *s))
				return (FALSE);
			count_collactable += (*s == 'C');
			s++;
		}
	}
	if (count_collactable == 0)
		return (FALSE);
	bomb->collactable = count_collactable;
	return (TRUE);
}
