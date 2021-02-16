/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:59:33 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/01 15:24:11 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_chek_number_spritebis(t_all *all, int nbsp)
{
	all->sprite->x[nbsp] = all->info->mapx + 0.5;
	all->sprite->y[nbsp] = all->info->mapy + 0.5;
	all->sprite->distancex[nbsp] = all->info->mapx - all->info->pos_x + 0.5;
	all->sprite->distancey[nbsp] = all->info->mapy - all->info->pos_y + 0.5;
	all->sprite->distance[nbsp] = ((all->info->pos_x - all->sprite->x[nbsp]) *
		(all->info->pos_x - all->sprite->x[nbsp]) + (all->info->pos_y -
		all->sprite->y[nbsp]) * (all->info->pos_y - all->sprite->y[nbsp]));
	all->sprite->mat[nbsp] = 1.0 / (all->info->planex *
		all->info->diry - all->info->dirx * all->info->planey);
	all->sprite->tformx[nbsp] = all->sprite->mat[nbsp] * (all->info->diry *
		all->sprite->distancex[nbsp] - all->info->dirx *
		all->sprite->distancey[nbsp]);
	all->sprite->tformy[nbsp] = all->sprite->mat[nbsp] * (-all->info->planey *
		all->sprite->distancex[nbsp] + all->info->planex *
		all->sprite->distancey[nbsp]);
	all->sprite->order[nbsp] = nbsp;
	all->sprite->count = nbsp + 1;
}

void	ft_chek_number_sprite(t_all *all)
{
	static int	spritenum;
	int			test;
	int			already;

	test = 0;
	already = 0;
	if (spritenum == SPRITE)
	{
		write(1, "error to much sprite\n-increase SPRITE\n", 38);
		exit(0);
	}
	if (all->sprite->restart + all->sprite->count == (SPRITE + 10))
		spritenum = 0;
	ft_chek_number_spritebis(all, spritenum);
	if (spritenum > 0)
		while (test < spritenum - 1)
		{
			if (all->sprite->x[spritenum] == all->sprite->x[test] &&
					all->sprite->y[spritenum] == all->sprite->y[test])
				already++;
			test++;
		}
	spritenum = (already == 0) ? spritenum + 1 : spritenum;
}

void	ft_stripe_loop(t_all *all, t_ray *ray, int i, int w)
{
	int	stripe;
	int	y;
	int	d;

	stripe = all->sprite->drawstx;
	while (stripe < all->sprite->drawendx)
	{
		ray->texx = (int)(256 * (stripe -
			(-all->sprite->spwidth / 2 + all->sprite->spscx)) *
			all->img->textw[5] / all->sprite->spwidth) / 256;
		y = all->sprite->drawsty;
		if (all->sprite->tformy[i] > 0 && stripe > 0 && stripe < w &&
				all->sprite->tformy[i] < all->sprite->buffz[stripe])
			while (y < all->sprite->drawendy)
			{
				d = y * 256 -
					all->info->res_y * 128 + all->sprite->spheight * 128;
				ray->texy = ((d * all->img->texth[5]) /
					all->sprite->spheight) / 256;
				ft_print_sprite(all, ray, stripe, y);
				y++;
			}
		stripe++;
	}
}

void	ft_sprite_calcul(t_all *all, t_ray *ray, int w, int h)
{
	int	nbsp;

	ft_sort_sprite(all);
	nbsp = all->sprite->count;
	while (nbsp-- > 1)
	{
		all->sprite->spscx = (int)((w / 2) *
			(1 + all->sprite->tformx[nbsp] / all->sprite->tformy[nbsp]));
		all->sprite->spheight = abs((int)(h / (all->sprite->tformy[nbsp])));
		all->sprite->drawsty = -all->sprite->spheight / 2 + h / 2;
		if (all->sprite->drawsty < 0)
			all->sprite->drawsty = 0;
		all->sprite->drawendy = all->sprite->spheight / 2 + h / 2;
		if (all->sprite->drawendy >= h)
			all->sprite->drawendy = h - 1;
		all->sprite->spwidth = abs((int)(h / (all->sprite->tformy[nbsp])));
		all->sprite->drawstx = -all->sprite->spwidth / 2 + all->sprite->spscx;
		if (all->sprite->drawstx < 0)
			all->sprite->drawstx = 0;
		all->sprite->drawendx = all->sprite->spwidth / 2 + all->sprite->spscx;
		if (all->sprite->drawendx >= w)
			all->sprite->drawendx = w - 1;
		ft_stripe_loop(all, ray, nbsp, w);
	}
	ft_init_sprite(all);
}
