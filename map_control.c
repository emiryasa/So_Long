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

static void wall_check(t_game *map);
static void invalid_char(t_game *so_long);
static void get_location(t_game *so_long, int x, int y);
static void count_check(t_game *so_long);

void size_check(t_game *map)
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

static void wall_check(t_game *map)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (++y < map->mapy)
	{
		if (map->map[y][0] != '1' || map->map[y][map->mapx - 1] != '1')
		{
			ft_printf("Error: There is gap in walls.");
			exit(1);
		}
	}
	while (x < map->mapx)
	{
		if (map->map[0][x] != '1' || map->map[map->mapy - 1][x] != '1')
		{
			ft_printf("Error: There is gap in walls.");
			exit(1);
		}
		x++;
	}
	invalid_char(map);
}

static void invalid_char(t_game *so_long)
{
	int x;
	int y;

	y = 0;
	while (y < so_long->mapy)
	{
		x = 0;
		while (x < so_long->mapx)
		{
			if (so_long->map[y][x] != 'P' && so_long->map[y][x] != 'E' && so_long->map[y][x] != 'C' && so_long->map[y][x] != '1' && so_long->map[y][x] != '0')
			{
				ft_printf("Error: Invalid character found");
				exit(1);
			}
			x++;
		}
		y++;
	}
	get_location(so_long, 0, 0);
}

static void get_location(t_game *so_long, int x, int y)
{
	y = 0; // 1den de başlatabiliriz.
	while (y < so_long->mapy)
	{
		x = 0;
		while (x < so_long->mapx)
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->p_count += 1;
				so_long->player.x = x;
				so_long->player.y = y;
			}
			else if (so_long->map[y][x] == 'E')
			{
				so_long->e_count += 1;
				so_long->exit.x = x;
				so_long->exit.y = y;
			}
			else if (so_long->map[y][x] == 'C')
				so_long->c_count += 1;
			x++;
		}
		y++;
	}
	count_check(so_long);
}

static void count_check(t_game *so_long)
{
	if (so_long->e_count != 1)
	{
		ft_printf("Error: There is more than one exit.");
		exit(1);
	}
	else if (so_long->c_count < 1)
	{
		ft_printf("Error: No no item to collect");
		exit(1);
	}
	else if (so_long->p_count != 1)
	{
		ft_printf("Error: There is more than one player.");
		exit(1);
	}
}