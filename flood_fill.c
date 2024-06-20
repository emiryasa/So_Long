/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyasa <eyasa@student.42istanbul.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:45:17 by eyasa             #+#    #+#             */
/*   Updated: 2024/06/13 21:23:05 by eyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void f_fill(t_game *map, int y, int x);
static void flf_check(t_game *so_long);
static char **ft_map_dup(const char **src);

void flood_fill(t_game *map)
{
    t_point player;

    map->mapcopy = ft_map_dup(map->map);
    player.x = map->player.x;
    player.y = map->player.y;
    f_fill(map, player.y, player.x);
    flf_check(map);
    free_map(map, 2);
}

static void f_fill(t_game *map, int y, int x)
{
    if (y < 0 || x < 0)
        return;
    if (y >= map->mapy || x >= map->mapx)
        return;
    if (map->mapcopy[y][x] == 'F' || map->mapcopy[y][x] == '1')
        return;
    map->mapcopy[y][x] = 'F';
    f_fill(map, y - 1, x);
    f_fill(map, y + 1, x);
    f_fill(map, y, x - 1);
    f_fill(map, y, x + 1);
}

static void flf_check(t_game *so_long)
{
    int i;
    int j;

    i = 0;
    while (so_long->mapcopy[i])
    {
        j = 0;
        while (so_long->mapcopy[i][j])
        {
            if (ft_strchr("PEC", so_long->mapcopy[i][j]))
            {
                ft_printf("Error: For flood fill");
                free_map(so_long, 2);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

static char **ft_map_dup(const char **src)
{
    char **dest;
    int i;
    int j;

    i = 0;
    while (src[i])
        i++;
    dest = (char **)malloc(sizeof(char *) * (i + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = (char *)malloc(sizeof(char) * (strlen(src[i]) + 1));
        if (!dest[i])
            return (NULL);
        j = 0;
        while (src[i][j])
        {
            dest[i][j] = src[i][j];
            j++;
        }
        dest[i][j] = '\0';
        i++;
    }
    dest[i] = NULL;
    return (dest);
}