/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:29:53 by jveras            #+#    #+#             */
/*   Updated: 2024/03/18 09:56:42 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	is_map_playable(char *path, char **map,
	t_bool reach_exit, t_point player)
{
	t_point	c;

	map = open_map(path);
	flood_fill(map, player, FALSE, (t_bool *)0);
	c = find_obj(map, (t_point){1, 1}, COLLECTIBLE);
	if (!reach_exit || (c.x || c.y))
		exit_or_collectibles_not_reachable_err(map);
	free_map(map);
}

t_bool	validate_map(char *path)
{
	t_point	p;
	t_point	e;
	t_point	c;
	t_bool	reach_exit;
	char	**map;

	map = open_map(path);
	is_map_irregular(map);
	check_map_characters(map);
	if (!is_map_closed(map))
		map_is_not_closed_err(map);
	p = find_obj(map, (t_point){1, 1}, PLAYER);
	e = find_obj(map, (t_point){1, 1}, EXIT);
	c = find_obj(map, (t_point){1, 1}, COLLECTIBLE);
	if ((!p.y && !p.x) || (!e.y && !e.x) || (!c.y && !c.x))
		could_not_find_obj_err(map);
	else if (has_duplicate(map, EXIT) || has_duplicate(map, PLAYER))
		has_double_e_or_p_err(map);
	reach_exit = FALSE;
	flood_fill(map, p, TRUE, &reach_exit);
	free_map(map);
	is_map_playable(path, map, reach_exit, p);
	return (FALSE);
}
