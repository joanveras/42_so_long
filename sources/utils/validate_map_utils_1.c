/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:28:07 by jveras            #+#    #+#             */
/*   Updated: 2024/03/13 10:44:19 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**open_map(char *path)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	map = malloc((count_lines(path) + 1) * sizeof(char *));
	if (!map)
	{
		write(2, "Memory allocation failure:: allocating (char **map)", 52);
		exit(EXIT_FAILURE);
	}
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = ft_strdup(line);
		if (ft_strchr(map[i], '\n'))
			map[i][ft_strlen(map[i]) - 1] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void flood_fill(char **map, t_point player, t_bool search_for_exit, t_bool *is_valid)
{
	if ((player.y < 0 || !map[player.y])
		|| (player.x < 0 || !map[player.y][player.x]))
		return ;
    if (map[player.y][player.x] == WALL || map[player.y][player.x] == 'X')
        return ;
    if (search_for_exit && map[player.y][player.x] == EXIT)
    {
		*is_valid = TRUE;
		return ;
	}
    map[player.y][player.x] = 'X';
    flood_fill(map, (t_point){player.x + 1, player.y}, search_for_exit, is_valid);
    flood_fill(map, (t_point){player.x - 1, player.y}, search_for_exit, is_valid);
    flood_fill(map, (t_point){player.x, player.y + 1}, search_for_exit, is_valid);
    flood_fill(map, (t_point){player.x, player.y - 1}, search_for_exit, is_valid);
}

t_bool	has_duplicate(char **map, int obj)
{
	int	x;
	int	y;
	int	flag;

	flag = FALSE;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == obj && flag)
				return (TRUE);
			else if (map[y][x] == obj)
				flag = TRUE;
			x++;
		}
		y++;
	}
	return (FALSE);
}

t_point	find_obj(char **map, t_point start, int obj)
{
	int	x;
	int	y;

	x = start.x;
	y = start.y;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == obj)
				return ((t_point){x, y});
			x++;
		}
		if (!map[y][x])
			x = 0;
		y++;
	}
	return ((t_point){FALSE, FALSE});
}

t_bool	is_map_closed(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((y == 0 || !map[y + 1]) && map[y][x] != WALL)
					return (FALSE);
			if ((x == 0 || !map[y][x + 1]) && map[y][x] != WALL)
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}
