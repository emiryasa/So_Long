/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:45:17 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/13 21:23:05 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_init(t_map *map)
{
	map->map = NULL;
	map->mapcopy = NULL;
	map->mapname = NULL;
	map->mapy = 0;
	map->mapx = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
	map->collectible.x = 0;
	map->collectible.y = 0;
}

int	main(int ac, char *av[])
{
	t_map	*map;

	if ((ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0) || ac != 2)
		ft_printf("Hatalı harita ismi.");
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_printf("Hafıza hatası.");
	map_init(map);
	map->mapname = av[1];
	read_map(map);
	free_map(map, 1);
	free(map);
}
void __attribute__ ((destructor))
a()
{
	system("leaks so_long");
}