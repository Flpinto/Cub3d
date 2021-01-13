/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:45:50 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/10 15:34:30 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     ft_mv_n(int key, t_all *all)
{
    if (key == TOP)
    {
        if (all->info->map[(int)all->info->pos_y][(int)(all->info->pos_x + all->info->dirx * 2 * 0.1)] != '1')
            all->info->pos_x = all->info->pos_x + all->info->dirx * 0.1;
        if (all->info->map[(int)(all->info->pos_y + all->info->diry * 2 * 0.1)][(int)(all->info->pos_x)] != '1')
            all->info->pos_y = all->info->pos_y + all->info->diry * 0.1;
    }
    if (key == BOT)
    {
        if (all->info->map[(int)all->info->pos_y][(int)(all->info->pos_x - all->info->dirx * 2 * 0.1)] != '1')
            all->info->pos_x = all->info->pos_x - all->info->dirx * 0.1;
        if (all->info->map[(int)(all->info->pos_y - all->info->diry * 2 * 0.1)][(int)(all->info->pos_x)] != '1')
            all->info->pos_y = all->info->pos_y - all->info->diry * 0.1;
    }
    if (key == RIGHT)
    {
        if (all->info->map[(int)all->info->pos_y][(int)(all->info->pos_x + all->info->planex * 2 * 0.1)] != '1')
            all->info->pos_x = all->info->pos_x + all->info->planex * 0.1;
        if (all->info->map[(int)(all->info->pos_y + all->info->planey * 2 * 0.1)][(int)(all->info->pos_x)] != '1')
            all->info->pos_y = all->info->pos_y + all->info->planey * 0.1;
    }
    if (key == LEFT)
    {
        if (all->info->map[(int)all->info->pos_y][(int)(all->info->pos_x - all->info->planex * 2 * 0.1)] != '1')
            all->info->pos_x = all->info->pos_x - all->info->planex * 0.1;
        if (all->info->map[(int)(all->info->pos_y - all->info->planey * 2 * 0.1)][(int)(all->info->pos_x)] != '1')
            all->info->pos_y = all->info->pos_y - all->info->planey * 0.1;
    }
    return (0);
}

int     ft_move_in_map(int key, t_all *all)
{

    ft_mv_n(key, all);
    return (0);
}