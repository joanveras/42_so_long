/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:26:51 by jveras            #+#    #+#             */
/*   Updated: 2024/03/12 10:10:57 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	conditions(t_win *win)
{
	if (win->map[win->player.position_y - 1][win->player.position_x] == EXIT)
	{
		if (win->player.collectibles == 0)
			exit_game(win);
	}
	else if (win->map[win->player.position_y - 1][win->player.position_x] \
		== COLLECTIBLE)
	{
		win->player.collectibles--;
	}
	if (win->map[win->player.position_y - 1][win->player.position_x] != EXIT)
	{
		win->map[win->player.position_y - 1][win->player.position_x] = PLAYER;
	}
	else if (win->map[win->player.position_y][win->player.position_x] != EXIT)
	{
		win->map[win->player.position_y][win->player.position_x] = EMPTY;
	}
}

void	up(t_win *win)
{
	mlx_loop_hook(win->mlx_ptr, up_walk_animation, win);
	if (win->map[win->player.position_y - 1][win->player.position_x] == WALL)
	{
		return ;
	}
	conditions(win);
	{
		win->player.position_y -= 1;
		win->player.steps++;
		ft_putnbr_fd(win->player.steps, 1);
		write(1, "\n", 1);
	}
	if (win->map[win->player.position_y + 1][win->player.position_x] == EXIT)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.key, win->player.position_x * SPRITE_SIZE,
			(win->player.position_y + 1) * SPRITE_SIZE);
	}
}
