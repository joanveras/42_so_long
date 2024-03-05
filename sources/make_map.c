#include "../includes/so_long.h"

static void	conditions(char	c, t_win *win, int x, int y)
{
	if (c == WALL)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == EMPTY)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.empty, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == PLAYER)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.idle.list[0], x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == COLLECTIBLE)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.coin, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (c == EXIT)
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.key, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	make_map(char **map, t_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			conditions(map[y][x], win, x, y);
			x++;
		}
		y++;
	}
}
