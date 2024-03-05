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
	win = initialize_X11_connection(map);
	player = find_obj(map, (t_point){1, 1}, PLAYER);
	win.player.position_x = player.x;
	win.player.position_y = player.y;
	win.map = map;
	load_tiles(&win);
	make_map(map, &win);
	mlx_loop_hook(win.mlx_ptr, idle_animation, &win);
	mlx_hook(win.win_ptr, ON_KEYDOWN, ON_KEYUP, handle_inputs, &win);
	mlx_hook(win.win_ptr, ON_KEYUP, ON_KEYDOWN, player_idle, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
