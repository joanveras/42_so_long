/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:21:11 by jveras            #+#    #+#             */
/*   Updated: 2024/03/18 09:50:33 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_point	player;
	t_win	win;
	char	**map;

	if (argc == 1)
		return (1);
	validate_map(argv[1]);
	map = open_map(argv[1]);
	initialize_x11_connection(&win, map);
	player = find_obj(map, (t_point){1, 1}, PLAYER);
	win.player.position_x = player.x;
	win.player.position_y = player.y;
	win.player.collectibles = count_collectibles(map);
	win.player.steps = 0;
	win.map = map;
	load_tiles(&win);
	make_map(map, &win);
	mlx_loop_hook(win.mlx_ptr, idle_animation, &win);
	mlx_hook(win.win_ptr, ON_KEYDOWN, ON_KEYUP, handle_inputs, &win);
	mlx_hook(win.win_ptr, ON_KEYUP, ON_KEYDOWN, player_idle, &win);
	mlx_hook(win.win_ptr, ON_DESTROY, 0, exit_game, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
