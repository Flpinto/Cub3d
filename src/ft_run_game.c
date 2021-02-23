/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:02:35 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/23 11:06:01 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_init_key(t_all *all)
{
	all->info->key[TOP] = 0;
	all->info->key[BOT] = 0;
	all->info->key[LEFT] = 0;
	all->info->key[RIGHT] = 0;
	all->info->key[RLEFT] = 0;
	all->info->key[RRIGHT] = 0;
	all->info->key[ESC] = 0;
}

void		ft_init_pos(t_all *all)
{
	all->info->pos_x = 0;
	all->info->pos_y = 0;
	all->info->dirx = 0;
	all->info->diry = -1;
	all->info->planex = 0;
	all->info->planey = 0.66;
	ft_init_direction(all);
	ft_init_key(all);
	ft_init_sprite(all);
}

t_all		ft_run_game(t_all all, int argc, char *argv)
{
	t_game		game;
	t_data		img;
	t_ray		ray;
	t_sprite	sprite;

	all.ray = &ray;
	all.game = &game;
	all.sprite = &sprite;
	all.img = &img;
	all.game->mlx = mlx_init();
	ft_size_window(&all);
	game.win = mlx_new_window(game.mlx,
		all.info->res_x, all.info->res_y, "Cub3d");
	img.img[0] = mlx_new_image(all.game->mlx, all.info->res_x,
	all.info->res_y);
	img = ft_get_img_by_file(img, all);
	ft_ray(&all);
	ft_save(img.addr[0], &all, argc, argv);
	mlx_put_image_to_window(game.mlx, game.win, img.img[0], 0, 0);
	mlx_hook(all.game->win, 33, 1L << 17, (*ft_exit_game), &all);
	mlx_hook(all.game->win, 2, 1L << 0, (*ft_keypress), &all);
	mlx_hook(all.game->win, 3, 1L << 1, (*ft_keyrelease), &all);
	mlx_loop_hook(all.game->mlx, (*ft_keypressed), &all);
	mlx_loop(all.game->mlx);
	return (all);
}
