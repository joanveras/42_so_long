#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "mlx.h"
# include "mlx_int.h"
# include "get_next_line.h"

# define SPRITE_SIZE 63

typedef enum
{
	FALSE,
	TRUE
}	t_bool;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3
};

enum
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_window_dimensions
{
	int	width;
	int	height;
}	t_window_dimensions;

typedef struct s_idle
{
	void		**list;
	int			num_sprites;
	int			current_sprite_index;
	int			frame_count;
	long int	frame_delay;
}	t_idle;

typedef struct s_down_walk
{
	void		**list;
	int			num_sprites;
	int			current_sprite_index;
	int			frame_count;
	long int	frame_delay;
}	t_down_walk;

typedef struct s_up_walk
{
	void		**list;
	int			num_sprites;
	int			current_sprite_index;
	int			frame_count;
	long int	frame_delay;
}	t_up_walk;

typedef struct s_left_walk
{
	void		**list;
	int			num_sprites;
	int			current_sprite_index;
	int			frame_count;
	long int	frame_delay;
}	t_left_walk;

typedef struct s_right_walk
{
	void		**list;
	int			num_sprites;
	int			current_sprite_index;
	int			frame_count;
	long int	frame_delay;
}	t_right_walk;

typedef struct s_tiles
{
	void			*empty;
	void			*wall;
	void			*coin;
	void			*key;
	t_idle			idle;
	t_down_walk		down_walk;
	t_up_walk		up_walk;
	t_left_walk		left_walk;
	t_right_walk	right_walk;
}	t_tiles;

typedef struct	s_player
{
	int	position_x;
	int	position_y;
}	t_player;

typedef struct s_win
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					w;
	int					h;
	char				**map;
	t_player			player;
	t_tiles				tiles;
	t_window_dimensions dimensions;
}	t_win;

t_point	find_obj(char **map, t_point start, int obj);

t_bool	is_map_closed(char **map);
t_bool	validate_map(char *path);
t_bool	has_duplicate(char **map, int obj);
t_bool	there_is_collectible_in_jail(char **map);

t_window_dimensions	window_dimensions(char **map);

t_win	initialize_X11_connection(char **map);

void	load_idle(t_win *win);
void	load_tiles(t_win *win);
void	load_side_walks_1(t_win	*win);
void	load_side_walks_2(t_win	*win);
void	load_static_sprites(t_win *win);
void	make_map(char **map, t_win *win);
void 	flood_fill(char **map, t_point player,
	t_bool search_for_exit, t_bool *is_valid);

int		idle_animation(t_win *win);
int		up_walk_animation(t_win *win);
int		down_walk_animation(t_win *win);
int		left_walk_animation(t_win *win);
int		player_idle(int key, t_win *win);
int		right_walk_animation(t_win *win);
int		handle_inputs(int key, t_win *win);

char	**open_map(char *path);

#endif