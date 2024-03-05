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
	while (map[y][x] != '\n')
	{
		width++;
		x++;
	}
	return ((t_window_dimensions)
		{width * SPRITE_SIZE, height * SPRITE_SIZE});
}

t_win	initialize_X11_connection(char **map)
{
	t_win				win;

	win.mlx_ptr = mlx_init();
	if (!win.mlx_ptr)
	{
		write(1, "NO CONNECTION WITH X11!", 24);
		exit(EXIT_FAILURE);
	}
	win.dimensions = window_dimensions(map);
	win.win_ptr = mlx_new_window(win.mlx_ptr,
		win.dimensions.width, win.dimensions.height, "so_long");
	if (!win.win_ptr)
	{
		write(1, "NO WINDOW!", 10);
		exit(EXIT_FAILURE);
	}
	if (win.dimensions.width == win.dimensions.height)
	{
		write(1, "error: The map must not be a SQUARE", 36);
		exit(EXIT_FAILURE);
	}
	return (win);
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
