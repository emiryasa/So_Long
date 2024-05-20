/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:21:02 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/18 21:49:34 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <fcntl.h>
# define M_WALL '1'
# define M_GROUND '0'
# define M_COLLECTIBLE 'C'
# define M_PLAYER 'P'
# define M_EXIT 'E'
# define M_ELEMENTS "10CPE"

# define BTN_EXIT 17

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53


typedef struct s_point
{
	int x;
	int y;
}			   t_point;

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		width;
	int		height;
	t_point	player;
	t_point	exit;
	t_point collectible;
}			   t_map;

void	map_read(t_map *map, int fd);

#endif