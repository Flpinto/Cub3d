/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:28:16 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/28 16:20:36 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_keypress(int key, t_all *all)
{
	all->info->key[key] = 1;
	return (0);
}

int		ft_keyrelease(int key, t_all *all)
{
	key = key;
	all->info->key[key] = 0;
	return (0);
}


int		ft_keypressed(t_all *all)
{
	if (all->info->key[TOP] == 1)
		ft_move_tb(TOP, all);
	if (all->info->key[BOT] == 1)
		ft_move_tb(BOT, all);
	if (all->info->key[RIGHT] == 1)
		ft_move_rl(RIGHT, all);
	if (all->info->key[LEFT] == 1)
		ft_move_rl(LEFT, all);
	if (all->info->key[RLEFT] == 1)
		ft_move_cam_left(all);
	if (all->info->key[RRIGHT] == 1)
		ft_move_cam_right(all);
	if (all->info->key[ESC] == 1)
		ft_exit_game(all);
	ft_loop(all);
	return (0);
}
