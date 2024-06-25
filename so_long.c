/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:45:17 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/25 16:54:55 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_init(t_game *map)
{
	map->map = NULL;
	map->mapcopy = NULL;
	map->mapname = NULL;
	map->mapy = 0;
	map->mapx = 0;
	map->p_count = 0;
	map->c_count = 0;
	map->collected_count = 0;
	map->e_count = 0;
	map->w_count = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit.x = 0;
	map->exit.y = 0;
	map->collectible.x = 0;
	map->collectible.y = 0;
	map->mlx = NULL;
	map->mlx_win = NULL;
}

void	mlx_actions(t_game *so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	so_long->mlx = mlx_init();
	so_long->mlx_win = mlx_new_window(so_long->mlx, so_long->mapx * 64,
			so_long->mapy * 64, "so_long");
	upload_image(so_long);
	put_image(so_long, x, y);
	mlx_key_hook(so_long->mlx_win, ft_key, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, ft_close, so_long);
	mlx_loop(so_long->mlx);
}

int	main(int ac, char *av[])
{
	t_game	*map;

	if (ac != 2)
		return (ft_printf("Error: Invalid argument number.\n"), -1);
	if ((ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0) || ac != 2)
		return (ft_printf("Error: Invalid map name.\n"), -1);
	map = (t_game *)malloc(sizeof(t_game));
	if (!map)
		ft_printf("Error: Allocation error.\n");
	map_init(map);
	map->mapname = av[1];
	read_map(map);
	size_check(map);
	flood_fill(map);
	mlx_actions(map);
}
