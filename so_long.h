/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:21:02 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/25 16:54:51 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# define M_ELEMENTS "10CPE"

# define BTN_EXIT 17

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53

typedef struct s_imgs
{
	void	*empty;
	void	*player;
	void	*wall;
	void	*collectable;
	void	*exit;
}			t_imgs;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	char	**map;
	char	**mapcopy;
	char	*mapname;
	int		mapy;
	int		mapx;
	int		p_count;
	int		c_count;
	int		e_count;
	int		w_count;
	int		move_count;
	int		collected_count;
	void	*mlx;
	void	*mlx_win;
	t_point	player;
	t_point	exit;
	t_point	collectible;
	t_imgs	imgs;
}			t_game;

void		read_map(t_game *map);
int			strlen_newline(char *line);
void		free_map(t_game *map, int n);
void		size_check(t_game *map);
void		flood_fill(t_game *so_long);
void		upload_image(t_game *so_long);
void		put_image(t_game *so_long, int x, int y);
int			ft_key(int keycode, t_game *so_long);
void		ft_up(t_game *so_long);
void		ft_left(t_game *so_long);
void		ft_right(t_game *so_long);
void		ft_down(t_game *so_long);
int			ft_close(t_game *so_long);
void		finish_message(t_game *solong, char c);

#endif