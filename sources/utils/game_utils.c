/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:27:12 by jveras            #+#    #+#             */
/*   Updated: 2024/03/18 09:50:46 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_window_dimensions	window_dimensions(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	height = 0;
	y = 0;
	while (map[y])
	{
		height++;
		y++;
	}
	width = 0;
	y = 0;
	x = 0;
	while (map[y][x])
	{
		width++;
		x++;
	}
	return ((t_window_dimensions)
		{width * SPRITE_SIZE, height * SPRITE_SIZE});
}

void	initialize_x11_connection(t_win *win, char **map)
{
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
	{
		write(1, "NO CONNECTION WITH X11!", 24);
		exit(EXIT_FAILURE);
	}
	win->dimensions = window_dimensions(map);
	if (win->dimensions.width == win->dimensions.height)
	{
		write(1, "error: The map must not be a SQUARE", 36);
		exit(EXIT_FAILURE);
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			win->dimensions.width, win->dimensions.height, "so_long");
	if (!win->win_ptr)
	{
		write(1, "NO WINDOW!", 10);
		exit(EXIT_FAILURE);
	}
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COLLECTIBLE)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
