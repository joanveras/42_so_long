/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:27:46 by jveras            #+#    #+#             */
/*   Updated: 2024/03/13 13:38:26 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_game(t_win *win)
{
	destroy_side_walk_list(win, win->tiles.right_walk.list);
	destroy_side_walk_list(win, win->tiles.down_walk.list);
	destroy_side_walk_list(win, win->tiles.left_walk.list);
	destroy_side_walk_list(win, win->tiles.up_walk.list);
	destroy_idle_list(win);
	mlx_destroy_image(win->mlx_ptr, win->tiles.empty);
	mlx_destroy_image(win->mlx_ptr, win->tiles.wall);
	mlx_destroy_image(win->mlx_ptr, win->tiles.coin);
	mlx_destroy_image(win->mlx_ptr, win->tiles.key);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free_map(win->map);
	free(win->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	count_lines(char *path)
{
	int		fd;
	int		counter;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "error: COULD NOT OPEN FILE\n", 27);
		exit(EXIT_FAILURE);
	}
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (counter);
}

void	load_tiles(t_win *win)
{
	load_idle(win);
	load_side_walks_1(win);
	load_side_walks_2(win);
	load_static_sprites(win);
}

int	player_idle(int key, t_win *win)
{
	if (key)
		mlx_loop_hook(win->mlx_ptr, idle_animation, win);
	return (0);
}

int	handle_inputs(int key, t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->tiles.empty, win->player.position_x * SPRITE_SIZE,
		win->player.position_y * SPRITE_SIZE);
	if (key == ESC)
		exit_game(win);
	else if (key == 'w')
		up(win);
	else if (key == 's')
		down(win);
	else if (key == 'a')
		left(win);
	else if (key == 'd')
		right(win);
	return (0);
}
