/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_manage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:44:54 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/03 10:45:50 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_loop(t_all *all)
{
	ft_ray(all);
	mlx_put_image_to_window(all->game->mlx,
		all->game->win, all->img->img[0], 0, 0);
}

int		ft_exit_game(t_all *all)
{
	mlx_destroy_window(all->game->mlx, all->game->win);
	ft_destroy_all(all);
	exit(0);
}

void	ft_size_window(t_all *all)
{
	int x;
	int y;

	mlx_get_screen_size(all->game->mlx, &x, &y);
	if (all->info->res_x > x)
		all->info->res_x = x;
	if (all->info->res_y > y)
		all->info->res_y = y;
	ft_init_pos(all);
}
