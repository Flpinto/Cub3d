/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:45:50 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/06 16:48:44 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_cw(t_all *all, double y, double x)
{
	int i;

	i = 0;
	if ((int)y < all->info->maplen - 1 && (int)y > 0)
		i++;
	if ((int)x < all->info->mapsize - 1 && (int)x > 0)
		i++;
	if (all->info->map[(int)y][(int)x] != '1')
		i = 2;
	else
		i = 0;
	return (i);
}

void	ft_move_tb(int key, t_all *all)
{
	if (key == TOP && ft_cw(all, (all->info->pos_y + all->info->diry * 0.1),
	(all->info->pos_x + all->info->dirx * 0.1)) == 2)
	{
		all->info->pos_x = all->info->pos_x + all->info->dirx * 0.1;
		all->info->pos_y = all->info->pos_y + all->info->diry * 0.1;
	}
	if (key == BOT && ft_cw(all, (all->info->pos_y - all->info->diry * 0.1),
	(all->info->pos_x - all->info->dirx * 0.1)) == 2)
	{
		all->info->pos_x = all->info->pos_x - all->info->dirx * 0.1;
		all->info->pos_y = all->info->pos_y - all->info->diry * 0.1;
	}
}

void	ft_move_rl(int key, t_all *all)
{
	if (key == RIGHT && ft_cw(all, (all->info->pos_y + all->info->planey
	* 0.1), (all->info->pos_x + all->info->planex * 0.1)) == 2)
	{
		all->info->pos_x = all->info->pos_x + all->info->planex * 0.1;
		all->info->pos_y = all->info->pos_y + all->info->planey * 0.1;
	}
	if (key == LEFT && ft_cw(all, (all->info->pos_y - all->info->planey
	* 0.1), (all->info->pos_x - all->info->planex * 0.1)) == 2)
	{
		all->info->pos_x = all->info->pos_x - all->info->planex * 0.1;
		all->info->pos_y = all->info->pos_y - all->info->planey * 0.1;
	}
}
