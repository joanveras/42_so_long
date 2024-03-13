/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jveras <verasjoan587@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:32:10 by jveras            #+#    #+#             */
/*   Updated: 2024/03/13 13:38:11 by jveras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + '0';
		write(fd, &c, 1);
	}
	else if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_idle_list(t_win *win)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(win->mlx_ptr, win->tiles.idle.list[i]);
		i++;
	}
	free(win->tiles.idle.list);
}

void	destroy_side_walk_list(t_win *win, void **list)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(win->mlx_ptr, list[i]);
		i++;
	}
	free(list);
}
