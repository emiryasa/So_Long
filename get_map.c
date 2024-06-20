/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:46:29 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/13 21:26:59 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int strlen_newline(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static void countline(t_game *map)
{
	char *str;
	int i;
	int fd;

	fd = open(map->mapname, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: File not open.");
		exit(1);
	}
	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		free(str);
		i++;
	}
	map->mapy = i;
	close(fd);
}

void read_map(t_game *map)
{
	int i;
	int fd;

	i = 0;
	countline(map);
	map->map = (char **)malloc(sizeof(char *) * (map->mapy + 1));
	if (!map->map)
	{
		ft_printf("Map açılmadı");
		exit(1);
	}
	fd = open(map->mapname, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: File not opened.");
		exit(1);
	}
	while (i < map->mapy)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	map->mapx = strlen_newline(map->map[0]);
	close(fd);
}

void free_map(t_game *map, int n)
{
	int i;

	i = 0;
	if (n == 1)
	{
		while (i < map->mapy)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	else
	{
		while (i < map->mapy)
		{
			free(map->mapcopy[i]);
			i++;
		}
		free(map->mapcopy);
	}
}