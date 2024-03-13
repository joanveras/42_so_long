/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:27:04 by jveras            #+#    #+#             */
/*   Updated: 2024/03/09 09:27:04 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	idle_animation(t_win *win)
{
	t_player	player;

	player = win->player;
	mlx_put_image_to_window(
		win->mlx_ptr,
		win->win_ptr,
		win->tiles.idle.list[win->tiles.idle.current_sprite_index],
		player.position_x * SPRITE_SIZE,
		player.position_y * SPRITE_SIZE
	);
	if ((win->tiles.idle.frame_count % win->tiles.idle.frame_delay) == 0)
	{
		win->tiles.idle.current_sprite_index = \
		(win->tiles.idle.current_sprite_index + 1) \
		% win->tiles.idle.num_sprites;
	}
	mlx_do_sync(win->mlx_ptr);
	win->tiles.idle.frame_count++;
	return (0);
}

int	down_walk_animation(t_win *win)
{
	t_player	player;

	player = win->player;
	mlx_put_image_to_window(
		win->mlx_ptr,
		win->win_ptr,
		win->tiles.down_walk.list[win->tiles.down_walk.current_sprite_index],
		player.position_x * SPRITE_SIZE,
		player.position_y * SPRITE_SIZE
	);
	if ((win->tiles.down_walk.frame_count % win->tiles.down_walk.frame_delay) == 0)
	{
		win->tiles.down_walk.current_sprite_index = \
		(win->tiles.down_walk.current_sprite_index + 1) \
		% win->tiles.down_walk.num_sprites;
	}
	mlx_do_sync(win->mlx_ptr);
	win->tiles.down_walk.frame_count++;
	return (0);
}

int	up_walk_animation(t_win *win)
{
	t_player	player;

	player = win->player;
	mlx_put_image_to_window(
		win->mlx_ptr,
		win->win_ptr,
		win->tiles.up_walk.list[win->tiles.up_walk.current_sprite_index],
		player.position_x * SPRITE_SIZE,
		player.position_y * SPRITE_SIZE
	);
	if ((win->tiles.up_walk.frame_count % win->tiles.up_walk.frame_delay) == 0)
	{
		win->tiles.up_walk.current_sprite_index = \
		(win->tiles.up_walk.current_sprite_index + 1) \
		% win->tiles.up_walk.num_sprites;
	}
	mlx_do_sync(win->mlx_ptr);
	win->tiles.up_walk.frame_count++;
	return (0);
}

int	left_walk_animation(t_win *win)
{
	t_player	player;

	player = win->player;
	mlx_put_image_to_window(
		win->mlx_ptr,
		win->win_ptr,
		win->tiles.left_walk.list[win->tiles.left_walk.current_sprite_index],
		player.position_x * SPRITE_SIZE,
		player.position_y * SPRITE_SIZE
	);
	if ((win->tiles.left_walk.frame_count % win->tiles.left_walk.frame_delay) == 0)
	{
		win->tiles.left_walk.current_sprite_index = \
		(win->tiles.left_walk.current_sprite_index + 1) \
		% win->tiles.left_walk.num_sprites;
	}
	mlx_do_sync(win->mlx_ptr);
	win->tiles.left_walk.frame_count++;
	return (0);
}

int	right_walk_animation(t_win *win)
{
	t_player		player;

	player = win->player;
	mlx_put_image_to_window(
		win->mlx_ptr,
		win->win_ptr,
		win->tiles.right_walk.list[win->tiles.right_walk.current_sprite_index],
		player.position_x * SPRITE_SIZE,
		player.position_y * SPRITE_SIZE
	);
	if ((win->tiles.right_walk.frame_count % win->tiles.right_walk.frame_delay) == 0)
	{
		win->tiles.right_walk.current_sprite_index = \
		(win->tiles.right_walk.current_sprite_index + 1) \
		% win->tiles.right_walk.num_sprites;
	}
	mlx_do_sync(win->mlx_ptr);
	win->tiles.right_walk.frame_count++;
	return (0);
}
