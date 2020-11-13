/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:45:50 by flpinto           #+#    #+#             */
/*   Updated: 2020/11/13 11:50:04 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     ft_mv_n(int key, t_all *all)
{
    if (key == TOP)
    {
        all->info->map[all->info->pos_y][all->info->pos_x] = '0';
        if (all->info->map[all->info->pos_y - 1][all->info->pos_x] != '1')
            all->info->pos_y--;
        all->info->map[all->info->pos_y][all->info->pos_x] = all->info->orient;
    }
    if (key == BOT)
    {
        all->info->map[all->info->pos_y][all->info->pos_x] = '0';
        if (all->info->map[all->info->pos_y + 1][all->info->pos_x] != '1')
            all->info->pos_y++;
        all->info->map[all->info->pos_y][all->info->pos_x] = all->info->orient;
    }
    if (key == RIGHT)
    {
        all->info->map[all->info->pos_y][all->info->pos_x] = '0';
        if (all->info->map[all->info->pos_y][all->info->pos_x + 1] != '1')
            all->info->pos_x++;
        all->info->map[all->info->pos_y][all->info->pos_x] = all->info->orient;
    }
    if (key == LEFT)
    {
        all->info->map[all->info->pos_y][all->info->pos_x] = '0';
        if (all->info->map[all->info->pos_y][all->info->pos_x - 1] != '1')
            all->info->pos_x--;
        all->info->map[all->info->pos_y][all->info->pos_x] = all->info->orient;
    }
    return (0);
}