/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:45:17 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/25 18:07:49 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_imag(t_game *so_long, int x, int y);

int	ft_key(int keycode, t_game *so_long)
{
	int	x;
	int	y;

	if (keycode == 13 || keycode == 126)
		ft_up(so_long);
	else if (keycode == 0 || keycode == 123)
		ft_left(so_long);
	else if (keycode == 2 || keycode == 124)
		ft_right(so_long);
	else if (keycode == 1 || keycode == 125)
		ft_down(so_long);
	else if (keycode == 53)
		ft_close(so_long);
	y = 0;
	put_image(so_long, x, y);
	return (0);
}

void	upload_image(t_game *so_long)
{
	int	x;
	int	y;

	so_long->imgs.wall = mlx_xpm_file_to_image(so_long->mlx,
			"textures/wall.xpm", &x, &y);
	so_long->imgs.empty = mlx_xpm_file_to_image(so_long->mlx,
			"textures/floor.xpm", &x, &y);
	so_long->imgs.player = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player.xpm", &x, &y);
	so_long->imgs.collectable = mlx_xpm_file_to_image(so_long->mlx,
			"textures/collectable.xpm", &x, &y);
	so_long->imgs.exit = mlx_xpm_file_to_image(so_long->mlx,
			"textures/exit.xpm", &x, &y);
	if (!so_long->imgs.wall || !so_long->imgs.empty || !so_long->imgs.player
		|| !so_long->imgs.collectable || !so_long->imgs.exit)
	{
		ft_printf("Error: Missing image.");
		free_map(so_long, 1);
		exit(1);
	}
}

void	put_image(t_game *so_long, int x, int y)
{
	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			put_imag(so_long, x, y);
			x++;
		}
		y++;
	}
}

static void	put_imag(t_game *so_long, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->imgs.empty,
		x * 64, y * 64);
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->imgs.wall, x * 64, y * 64);
	else if (so_long->map[y][x] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->imgs.exit, x * 64, y * 64);
	else if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->imgs.collectable, x * 64, y * 64);
	else if (so_long->map[y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->imgs.player, x * 64, y * 64);
	if (so_long->map[y][x] == 'E' && so_long->player.x == so_long->exit.x
		&& so_long->exit.y == so_long->player.y)
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->imgs.player, x * 64, y * 64);
}

void	finish_message(t_game *solong, char c)
{
	if (c == 'w')
	{
		free_map(solong, 1);
		ft_printf("Congratulations, you won.");
	}
	free(solong);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	exit(0);
}
