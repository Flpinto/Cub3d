/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_direction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:24:17 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 15:01:43 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void     init_direction(t_all *all, int y, int x)
{
    all->info->pos_x = (all->info->pos_x == 0) ? x + 0.5 : all->info->pos_x;
	all->info->pos_y = (all->info->pos_y == 0) ? y + 0.5 : all->info->pos_y;
	if (all->info->map[y][x] == 'E')
	{
		all->info->dirx = 1;
		all->info->diry = 0;
		all->info->planex = 0;
		all->info->planey = 0.66;
	}
	if (all->info->map[y][x] == 'N')
	{
		all->info->dirx = 0;
		all->info->diry = -1;
		all->info->planex = 0.66;
		all->info->planey = 0;
	}
    if (all->info->map[y][x] == 'W')
	{
		all->info->dirx = -1;
		all->info->diry = 0;
		all->info->planex = 0;
		all->info->planey = -0.66;
	}
	if (all->info->map[y][x] == 'S')
	{
		all->info->dirx = 0;
		all->info->diry = 1;
		all->info->planex = -0.66;
		all->info->planey = 0;
	}
}

void    ft_init_direction(t_all *all)
{
    int     x;
    int     y;

    y = 0;
    while (all->info->map[y] && y < all->info->maplen)
    {
        x = 0;
        while (all->info->map[y][x] && x < all->info->mapsize)
        {
            if (all->info->map[y][x] == 'N' || all->info->map[y][x] == 'S' || 
					all->info->map[y][x] == 'W' || all->info->map[y][x] == 'E')
            {
			    init_direction(all, y, x);
				if (all->info->map[y][x] == 'N' || all->info->map[y][x] == 'S' 
						|| all->info->map[y][x] == 'W' || all->info->map[y][x] == 'E')
					all->info->map[y][x] = '0';
			}
            x++;
        }
        y++;
    }
}