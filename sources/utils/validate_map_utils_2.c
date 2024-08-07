/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:56:44 by jveras            #+#    #+#             */
/*   Updated: 2024/03/18 10:45:51 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

void	check_map_characters(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == WALL || map[y][x] == EMPTY
				|| map[y][x] == COLLECTIBLE || map[y][x] == PLAYER
					|| map[y][x] == EXIT)
			{
				x++;
				continue ;
			}
			invalid_map_character_err(map);
		}
		y++;
	}
}

void	is_map_irregular(char **map)
{
	int		y;
	size_t	len;

	y = 0;
	while (map[y])
	{
		y++;
	}
	len = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if (ft_strlen(map[y]) != len)
			is_irregular_err(map);
		y++;
	}
}
