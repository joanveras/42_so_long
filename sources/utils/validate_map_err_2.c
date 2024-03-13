/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_err_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:50:17 by jveras            #+#    #+#             */
/*   Updated: 2024/03/13 09:46:28 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	invalid_map_character_err(char **map)
{
	free_map(map);
	write(2, "error: FOUND INVALID MAP CHARACTER\n", 36);
	exit(EXIT_FAILURE);
}
