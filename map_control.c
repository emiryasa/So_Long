/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:25:15 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/13 21:28:59 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	size_check(t_map *map)
{
	int i;
	int x;

	i = 0;
	x = map->mapx;
	while (i < map->mapy)
	{
		if (x != strlen_newline(map->map[i]))
		{
			ft_printf("Error: Map size.");
			exit(1);
		}
		i++;
	}
	if (x > 40 || map->mapy > 22)
	{
		ft_printf("Error: The map is very big.");
		exit(1);
	}
	wall_check(map);
}

static void	wall_check(t_map *so_long)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (++y < so_long->mapy)
	{
		if (so_long->map[y][0] != '1' || so_long->map[y][so_long->mapx
			- 1] != '1')
		{
			ft_printf("Error: There is gap in walls.");
			exit(1);
		}
	}
	while (x < so_long->mapx)
	{
		if (so_long->map[0][x] != '1' || so_long->map[so_long->mapy
			- 1][x] != '1')
		{
			ft_printf("Error: There is gap in walls.");
			exit(1);
		}
		x++;
	}
	invalid_char(so_long, x, y);
}
