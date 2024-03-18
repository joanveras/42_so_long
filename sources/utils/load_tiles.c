/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:27:19 by jveras            #+#    #+#             */
/*   Updated: 2024/03/18 09:53:23 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	*load_sprite(t_win *win, char *path)
{
	void	*sprite;

	sprite = mlx_xpm_file_to_image(
			win->mlx_ptr,
			path,
			&(win->w),
			&(win->h)
			);
	return (sprite);
}

void	load_idle(t_win *win)
{
	t_idle	idle;

	idle.current_sprite_index = 0;
	idle.frame_count = 0;
	idle.frame_delay = 4000;
	idle.num_sprites = 8;
	idle.list = malloc(sizeof(void *) * idle.num_sprites);
	idle.list[0] = load_sprite(win, "textures/idle/idle_1.xpm");
	idle.list[1] = load_sprite(win, "textures/idle/idle_2.xpm");
	idle.list[2] = load_sprite(win, "textures/idle/idle_3.xpm");
	idle.list[3] = load_sprite(win, "textures/idle/idle_4.xpm");
	idle.list[4] = load_sprite(win, "textures/idle/idle_5.xpm");
	idle.list[5] = load_sprite(win, "textures/idle/idle_6.xpm");
	idle.list[6] = load_sprite(win, "textures/idle/idle_7.xpm");
	idle.list[7] = load_sprite(win, "textures/idle/idle_8.xpm");
	{
		win->tiles.idle = idle;
	}
}

void	load_side_walks_1(t_win	*win)
{
	t_down_walk		down_walk;
	t_up_walk		up_walk;

	down_walk.current_sprite_index = 0;
	down_walk.frame_count = 0;
	down_walk.frame_delay = 4200;
	down_walk.num_sprites = 2;
	down_walk.list = malloc(sizeof(void *) * down_walk.num_sprites);
	down_walk.list[0] = load_sprite(win, "textures/side_walks/down_walk_1.xpm");
	down_walk.list[1] = load_sprite(win, "textures/side_walks/down_walk_2.xpm");
	up_walk.current_sprite_index = 0;
	up_walk.frame_count = 0;
	up_walk.frame_delay = 4200;
	up_walk.num_sprites = 2;
	up_walk.list = malloc(sizeof(void *) * up_walk.num_sprites);
	up_walk.list[0] = load_sprite(win, "textures/side_walks/up_walk_1.xpm");
	up_walk.list[1] = load_sprite(win, "textures/side_walks/up_walk_2.xpm");
	{
		win->tiles.down_walk = down_walk;
		win->tiles.up_walk = up_walk;
	}
}

void	load_side_walks_2(t_win	*win)
{
	t_left_walk			left_walk;
	t_right_walk		right_walk;

	left_walk.current_sprite_index = 0;
	left_walk.frame_count = 0;
	left_walk.frame_delay = 4200;
	left_walk.num_sprites = 2;
	left_walk.list = malloc(sizeof(void *) * left_walk.num_sprites);
	left_walk.list[0]
		= load_sprite(win, "textures/side_walks/left_side_walk_1.xpm");
	left_walk.list[1]
		= load_sprite(win, "textures/side_walks/left_side_walk_2.xpm");
	right_walk.current_sprite_index = 0;
	right_walk.frame_count = 0;
	right_walk.frame_delay = 4200;
	right_walk.num_sprites = 2;
	right_walk.list = malloc(sizeof(void *) * right_walk.num_sprites);
	right_walk.list[0]
		= load_sprite(win, "textures/side_walks/right_side_walk_1.xpm");
	right_walk.list[1]
		= load_sprite(win, "textures/side_walks/right_side_walk_2.xpm");
	{
		win->tiles.left_walk = left_walk;
		win->tiles.right_walk = right_walk;
	}
}

void	load_static_sprites(t_win *win)
{
	void	*empty_space;
	void	*wall;
	void	*coin;
	void	*key;

	empty_space = load_sprite(win, "textures/empty_space.xpm");
	wall = load_sprite(win, "textures/wall.xpm");
	coin = load_sprite(win, "textures/coin.xpm");
	key = load_sprite(win, "textures/key.xpm");
	{
		win->tiles.empty = empty_space;
		win->tiles.wall = wall;
		win->tiles.coin = coin;
		win->tiles.key = key;
	}
}
