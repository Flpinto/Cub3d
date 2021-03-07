/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_putpixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:24:29 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/07 11:15:34 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_check_tex_view(t_ray *ray)
{
	int view;

	view = 4;
	if (ray->side != 0)
	{
		if (ray->side == 1 && view == 4)
			view = 1;
		if (ray->side == 3 && view == 4)
			view = 3;
		if (ray->side == 4 && view == 4)
			view = 2;
	}
	return (view);
}

void	ft_print_color(t_all *all, int x, int y, int color)
{
	int (*pix_array)[all->info->res_x];

	all->img->addr[0] = mlx_get_data_addr(all->img->img[0],
		&all->img->bits_per_pixel[0], &all->img->line_length[0],
		&all->img->endian[0]);
	pix_array = (void *)all->img->addr[0];
	pix_array[y][x] = color;
}

void	ft_print_view(t_all *all, t_ray *ray, t_vect *vect, int view)
{
	int (*pix_array);
	int (*pixtxt_array);
	int idx;

	all->img->addr[view] = mlx_get_data_addr(all->img->img[view],
			&all->img->bits_per_pixel[view],
			&all->img->line_length[view],
			&all->img->endian[view]);
	if ((idx = all->info->res_x * vect->y + vect->x) >=
			all->info->res_y * all->info->res_x)
		idx = all->info->res_y * all->info->res_x;
	if (ray->texy < 1)
		ray->texy = 1;
	pix_array = (void *)all->img->addr[0];
	pixtxt_array = (void *)all->img->addr[view];
	pix_array[idx] =
		pixtxt_array[all->img->textw[view] * ray->texy + ray->texx];
}

void	ft_print_sprite(t_all *all, t_ray *ray, int x, int y)
{
	int (*pix_array)[all->info->res_x];
	int (*pixtxt_array)[all->img->textw[5]];
	int view;

	view = 5;
	all->img->addr[view] = mlx_get_data_addr(all->img->img[view],
			&all->img->bits_per_pixel[view],
			&all->img->line_length[view],
			&all->img->endian[view]);
	pix_array = (void *)all->img->addr[0];
	pixtxt_array = (void *)all->img->addr[view];
	if (pixtxt_array[ray->texy][ray->texx] != -16777216 &&
			pixtxt_array[ray->texy][ray->texx] != 461842 &&
			pixtxt_array[ray->texy][ray->texx] != 0)
		pix_array[y][x] = pixtxt_array[ray->texy][ray->texx];
}

void	ft_my_put_pixel(t_all *all, t_ray *ray, t_vect *vect, int x)
{
	ray->texpos = (ray->drawst - all->info->res_y /
	2 + ray->lineh / 2) * ray->step;
	vect->y = 0;
	vect->x = x;
	while (vect->y < ray->drawst)
	{
		ft_print_color(all, vect->x, vect->y, all->img->crgb);
		vect->y++;
	}
	while (vect->y < ray->drawend)
	{
		ray->texy = (int)ray->texpos;
		ray->texpos = ray->texpos + ray->step;
		ft_print_view(all, ray, vect, ft_check_tex_view(ray));
		vect->y++;
	}
	while (vect->y < all->info->res_y)
	{
		ft_print_color(all, vect->x, vect->y, all->img->frgb);
		vect->y++;
	}
}
