/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:29:53 by jveras            #+#    #+#             */
/*   Updated: 2024/03/13 09:01:20 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_bool	validate_map(char *path)
{
	t_point	P;
	t_point	E;
	t_point	C;
	t_bool	reach_exit;
	char	**map;

	map = open_map(path);
	is_map_irregular(map);
	check_map_characters(map);
	if (!is_map_closed(map))
		map_is_not_closed_err(map);
	P = find_obj(map, (t_point){1, 1}, PLAYER);
	E = find_obj(map, (t_point){1, 1}, EXIT);
	C = find_obj(map, (t_point){1, 1}, COLLECTIBLE);
	if ((!P.y && !P.x) || (!E.y && !E.x) || (!C.y && !C.x))
		could_not_find_obj_err(map);
	else if (has_duplicate(map, EXIT) || has_duplicate(map, PLAYER))
		has_double_E_or_P_err(map);
	reach_exit = FALSE;
	flood_fill(map, P, TRUE, &reach_exit);
	free_map(map);
	map = open_map(path);
	flood_fill(map, P, FALSE, (t_bool *)0);
	C = find_obj(map, (t_point){1, 1}, COLLECTIBLE);
	if (!reach_exit || (C.x || C.y))
		exit_or_collectibles_not_reachable_err(map);
	free_map(map);
	return (FALSE);
}
