/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:29:45 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/23 12:00:30 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_move_cam_left(t_all *all)
{
	double oldpanex;
	double olddirx;

	olddirx = all->info->dirx;
	oldpanex = all->info->planex;
	all->info->dirx = all->info->dirx * cos(0.1) - all->info->diry * sin(0.1);
	all->info->diry = olddirx * sin(0.1) + all->info->diry * cos(0.1);
	all->info->planex = all->info->planex * cos(0.1) -
	all->info->planey * sin(0.1);
	all->info->planey = oldpanex * sin(0.1) + all->info->planey * cos(0.1);
}

void	ft_move_cam_right(t_all *all)
{
	double oldpanex;
	double olddirx;

	olddirx = all->info->dirx;
	oldpanex = all->info->planex;
	all->info->dirx = all->info->dirx * cos(-0.1) -
	all->info->diry * sin(-0.1);
	all->info->diry = olddirx * sin(-0.1) + all->info->diry * cos(-0.1);
	all->info->planex =
		all->info->planex * cos(-0.1) - all->info->planey * sin(-0.1);
	all->info->planey = oldpanex * sin(-0.1) + all->info->planey * cos(-0.1);
}
