/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_err_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:58:19 by jveras            #+#    #+#             */
/*   Updated: 2024/03/13 10:08:08 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_is_not_closed_err(char **map)
{
	free_map(map);
	write(2, "error: MAP IS NOT SORROUNDED BY WALLS\n", 39);
	exit(EXIT_FAILURE);
}

void	has_double_E_or_P_err(char **map)
{
	free_map(map);
	write(2, "error: MAP HAS DUPLICATE >> (Exit) or (Player)\n", 48);
	exit(EXIT_FAILURE);
}

void	could_not_find_obj_err(char **map)
{
	free_map(map);
	write(2,
		"error: MAP HAS NOT OBJ >> (Exit), (Player) or (Collectible)\n",
		61);
	exit(EXIT_FAILURE);
}

void	exit_or_collectibles_not_reachable_err(char **map)
{
	free_map(map);
	write(2,
		"error: IT'S NOT POSSIBLE TO REACH >> (Exit) or (Collectible(s))\n",
		65);
	exit(EXIT_FAILURE);
}

void	is_irregular_err(char **map)
{
	free_map(map);
	write(2, "error: MAP IS IRREGULAR\n", 25);
	exit(EXIT_FAILURE);
}
