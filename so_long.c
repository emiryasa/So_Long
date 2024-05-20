/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:45:17 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/18 21:59:59 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map)
{
	map->map = NULL;
	map->map_copy = NULL;
	map->width = 0;
	map->height = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
	map->collectible.x = 0;
	map->collectible.y = 0;
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		fd;
	if ((ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0) || argc != 2)
		ft_printf("Hatalı harita ismi.");
	map = (t_map *)malloc(sizeof(t_map *));
	if (!map)
		ft_printf("Hafıza hatası.");
	map_init(map);
	fd = open(argv[1], O_RDONLY);
	map_read(map, fd);
	free(map);
	close(fd);
	return (0);
}


void __attribute__((destructor)) a(void)
{
	    system("leaks so_long");
}