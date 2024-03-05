#include "../includes/so_long.h"

static void	map_is_not_closed_err(void)
{
	write(1, "error: MAP IS NOT SORROUNDED BY WALLS\n", 39);
	exit(EXIT_FAILURE);
}

static void	has_double_E_or_P_err(void)
{
	write(1, "error: MAP HAS DUPLICATE >> (Exit) or (Player)\n", 48);
	exit(EXIT_FAILURE);
}

static void	could_not_find_obj_err(void)
{
	write(1,
		"error: MAP HAS NOT OBJ >> (Exit), (Player) or (Collectible)\n",
		61);
	exit(EXIT_FAILURE);
}

static void	exit_or_collectibles_not_reachable_err(void)
{
	write(1,
		"error: IT'S NOT POSSIBLE TO REACH >> (Exit) or (Collectible(s))\n",
		65);
	exit(EXIT_FAILURE);
}

t_bool	validate_map(char *path)
{
	t_point	P;
	t_point	E;
	t_point	C;
	t_bool	reach_exit;
	char	**map;

	map = open_map(path);
	if (!is_map_closed(map))
		map_is_not_closed_err();
	P = find_obj(map, (t_point){1, 1}, PLAYER);
	E = find_obj(map, (t_point){1, 1}, EXIT);
	C = find_obj(map, (t_point){1, 1}, COLLECTIBLE);
	if ((!P.y && !P.x) || (!E.y && !E.x) || (!C.y && !C.x))
		could_not_find_obj_err();
	else if (has_duplicate(map, EXIT) || has_duplicate(map, PLAYER))
		has_double_E_or_P_err();
	reach_exit = FALSE;
	flood_fill(map, P, TRUE, &reach_exit);
	map = open_map(path);
	flood_fill(map, P, FALSE, (t_bool *)0);
	C = find_obj(map, (t_point){1, 1}, COLLECTIBLE);
	free(map);
	if (!reach_exit || (C.x || C.y))
		exit_or_collectibles_not_reachable_err();
	return (FALSE);
}
