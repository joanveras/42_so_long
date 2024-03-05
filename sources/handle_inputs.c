#include "../includes/so_long.h"

static void	up(t_win *win)
{
	mlx_loop_hook(win->mlx_ptr, up_walk_animation, win);
	if (win->map[win->player.position_y - 1][win->player.position_x] == WALL)
		return ;
	else if (win->map[win->player.position_y - 1][win->player.position_x] != EXIT)
	{
		win->map[win->player.position_y - 1][win->player.position_x] = PLAYER;
	}
	else if (win->map[win->player.position_y][win->player.position_x] != EXIT)
	{
		win->map[win->player.position_y][win->player.position_x] = EMPTY;
	}
	win->player.position_y -= 1;
	if (win->map[win->player.position_y + 1][win->player.position_x] == EXIT)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.key, win->player.position_x * SPRITE_SIZE,
			(win->player.position_y + 1) * SPRITE_SIZE);
	}
}

static void	down(t_win *win)
{
	mlx_loop_hook(win->mlx_ptr, down_walk_animation, win);
	if (win->map[win->player.position_y + 1][win->player.position_x] == WALL)
		return ;
	else if (win->map[win->player.position_y + 1][win->player.position_x] != EXIT)
	{
		win->map[win->player.position_y + 1][win->player.position_x] = PLAYER;
	}
	else if (win->map[win->player.position_y][win->player.position_x] != EXIT)
	{
		win->map[win->player.position_y][win->player.position_x] = EMPTY;
	}
	win->player.position_y += 1;
	if (win->map[win->player.position_y - 1][win->player.position_x] == EXIT)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->tiles.key, win->player.position_x * SPRITE_SIZE,
			(win->player.position_y - 1) * SPRITE_SIZE);
	}
}

static void	left(t_win *win)
{
	mlx_loop_hook(win->mlx_ptr, left_walk_animation, win);
	if (win->map[win->player.position_y][win->player.position_x - 1] == WALL)
		return ;
	win->map[win->player.position_y][win->player.position_x] = EMPTY;
	win->map[win->player.position_y][win->player.position_x - 1] = PLAYER;
	win->player.position_x -= 1;
}

static void	right(t_win *win)
{
	mlx_loop_hook(win->mlx_ptr, right_walk_animation, win);
	if (win->map[win->player.position_y][win->player.position_x + 1] == WALL)
		return ;
	win->map[win->player.position_y][win->player.position_x] = EMPTY;
	win->map[win->player.position_y][win->player.position_x + 1] = PLAYER;
	win->player.position_x += 1;
}

int	handle_inputs(int key, t_win *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
		win->tiles.empty, win->player.position_x * SPRITE_SIZE,
		win->player.position_y * SPRITE_SIZE);
	if (key == 'w')
		up(win);
	else if (key == 's')
		down(win);
	else if (key == 'a')
		left(win);
	else if (key == 'd')
		right(win);
	return (0);
}
