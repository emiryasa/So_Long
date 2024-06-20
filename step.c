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

void ft_up(t_game *so_long)
{
    char next_step;

    next_step = so_long->map[so_long->player.y - 1][so_long->player.x];
    if (next_step == '1')
        return;
    so_long->move_count++;
    ft_printf("Step count: %d\n", so_long->move_count);
    if (next_step == 'C')
        so_long->collected_count++;
    else if (next_step == 'E' && so_long->collected_count == so_long->c_count)
        finish_message(so_long, 'w');
    so_long->map[so_long->player.y][so_long->player.x] = '0';
    so_long->player.y--;
    so_long->map[so_long->player.y][so_long->player.x] = 'P';
    if (so_long->map[so_long->exit.y][so_long->exit.x] != 'E')
        so_long->map[so_long->exit.y][so_long->exit.x] = 'E';
}

void ft_left(t_game *so_long)
{
    char next_step;

    next_step = so_long->map[so_long->player.y][so_long->player.x - 1];
    if (next_step == '1')
        return;
    so_long->move_count++;
    ft_printf("Step count: %d\n", so_long->move_count);
    if (next_step == 'C')
        so_long->collected_count++;
    else if (next_step == 'E' && so_long->c_count == so_long->collected_count)
        finish_message(so_long, 'w');
    so_long->map[so_long->player.y][so_long->player.x] = '0';
    so_long->player.x--;
    so_long->map[so_long->player.y][so_long->player.x] = 'P';
    if (so_long->map[so_long->exit.y][so_long->exit.x] != 'E')
        so_long->map[so_long->exit.y][so_long->exit.x] = 'E';
}

void ft_right(t_game *so_long)
{
    char next_step;

    next_step = so_long->map[so_long->player.y][so_long->player.x + 1];
    if (next_step == '1')
        return;
    so_long->move_count++;
    ft_printf("Step count: %d\n", so_long->move_count);
    if (next_step == 'C')
        so_long->collected_count++;
    else if (next_step == 'E' && so_long->c_count == so_long->collected_count)
        finish_message(so_long, 'w');
    so_long->map[so_long->player.y][so_long->player.x] = '0';
    so_long->player.x++;
    so_long->map[so_long->player.y][so_long->player.x] = 'P';
    if (so_long->map[so_long->exit.y][so_long->exit.x] != 'E')
        so_long->map[so_long->exit.y][so_long->exit.x] = 'E';
}

void ft_down(t_game *so_long)
{
    char next_step;

    next_step = so_long->map[so_long->player.y + 1][so_long->player.x];
    if (next_step == '1')
        return;
    so_long->move_count++;
    ft_printf("Step count: %d\n", so_long->move_count);
    if (next_step == 'C')
        so_long->collected_count++;
    else if (next_step == 'E' && so_long->collected_count == so_long->c_count)
        finish_message(so_long, 'w');
    so_long->map[so_long->player.y][so_long->player.x] = '0';
    so_long->player.y++;
    so_long->map[so_long->player.y][so_long->player.x] = 'P';
    if (so_long->map[so_long->exit.y][so_long->exit.x] != 'E')
        so_long->map[so_long->exit.y][so_long->exit.x] = 'E';
}

int ft_close(t_game *so_long)
{
    ft_printf("Game closed.");
    free_map(so_long, 1);
    exit(1);
}
