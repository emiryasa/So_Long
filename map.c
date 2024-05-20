/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:46:29 by eyasa             #+#    #+#             */
/*   Updated: 2024/05/18 22:09:16 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// void	check_width(char *line, t_map *map)
// {
// 	if (map->height == 0)
// 	{
// 		map->width = ft_custom_strlen(line);
// 	}
// 	else if (map->width != ft_custom_strlen(line))
// 	{
// 		free(line);
// 		// handle_error("Invalid map", -1, map);
// 	}
// }
void add_row(t_map *map, char *row, int height)
{
    char **new_map;
    int i;

    new_map = (char **)malloc(sizeof(char *) * (height + 1));
    if (!new_map)
    {
        ft_printf("Memory error.");
        exit(1);
    }
    i = 0;
    while (i < height)
    {
        new_map[i] = ft_strdup(map->map[i]);
        free(map->map[i]);
        i++;
    }
    new_map[i] = ft_strdup(row);
    if (map->map != NULL)
        free(map->map);
    map->map = new_map;
}
void	*my_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
	{
		ft_printf("Yeniden boyutlandırma başarısız oldu!\n");
		free(ptr);
		exit(EXIT_FAILURE);
	}
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}
void	add_line(t_map *map, char *line)
{
	map->map = (char **)my_realloc(map->map, sizeof(char *) * (map->height
				+ 1));
	map->map[map->height] = ft_strdup(line);
	map->map_copy = (char **)my_realloc(map->map_copy, sizeof(char *)
			* (map->height + 1));
	map->map_copy[map->height] = ft_strdup(line);
	if (!map->map[map->height] || !map->map || !map->map_copy
		|| !map->map_copy[map->height])
		// handle_error("Memory allocation failed", -1, map);
	map->height++;
}
void map_read(t_map *map, int fd)
{
    char *row;
    int height;
	
    height = 0;
    map->map = (char **)malloc(sizeof(char *) * (1));
    if (!map->map)
    {
        ft_printf("Map açılmadı");
        exit(1);
    }
    while (1)
    {
        row = get_next_line(fd);
        if (!row)
		{
			free(row);
            break;
		}
		map->height = height;
        add_line(map, row);
		height++;
        ft_printf("%s\n", row);
        free(row);
        height++;
    }
}

