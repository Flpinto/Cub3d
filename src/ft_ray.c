/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:51:47 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/11 16:29:24 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     ft_init_ray(t_ray *ray)
{
    ray->raydirx = 0;
	ray->raydiry = 0;
	ray->lineh = 0;
	ray->drawst = 0;
	ray->drawend = 0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->perpwalldist = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->side = 0;
	ray->wallx = 0;
	ray->texx = 0;
	ray->texy = 0;
	ray->step = 0;
	ray->hit = 0;
	return (0);
}

int		sidetext(t_ray ray)
{
	int texture;

	texture = 4;
	if (ray.side != 0)
	{
		texture = (ray.side == 1) && (texture == 4) ? 1 : texture;
		texture = (ray.side == 3) && (texture == 4) ? 3 : texture;
		texture = (ray.side == 4) && (texture == 4) ? 2 : texture;
	}
	return (texture);
}

void	my_put_pixel(t_all *all, int x, int y, int color)
{
	int (*pix_array)[all->info->res_x];

	all->img->addr[0] = mlx_get_data_addr(all->img->img[0], &all->img->bits_per_pixel[0],
			&all->img->line_length[0], &all->img->endian[0]);
	pix_array = (void *)all->img->addr[0];
	pix_array[y][x] = color;
}

void	ft_put_pixeltex(t_all *all, t_ray ray, t_vect vect, int texture)
{
	int (*pix_array);
	int (*pixtxt_array);
	int idx;

	all->img->addr[texture] = mlx_get_data_addr(all->img->img[texture],
			&all->img->bits_per_pixel[texture],
			&all->img->line_length[texture],
			&all->img->endian[texture]);
	if ((idx = all->info->res_x * vect.y + vect.x) >=
			all->info->res_y * all->info->res_x)
		idx = all->info->res_y * all->info->res_x;
	if (ray.texy < 1)
		ray.texy = 1;
	pix_array = (void *)all->img->addr[0];
	pixtxt_array = (void *)all->img->addr[texture];
	pix_array[idx] =
		pixtxt_array[all->img->textw[texture] * ray.texy + ray.texx];
}

int		ft_check_hit(t_all *all, t_ray *ray)
{
	if (all->info->map[(int)all->info->mapy][(int)all->info->mapx] != '1')
		ray->hit = 1;
	if (all->info->map[(int)all->info->mapy][(int)all->info->mapx] != '2')
		ray->hit = 1;
	return (0);
}

int     ft_ray(t_all *all)
{
    t_ray   ray;
    t_vect  vect;
    double  w;
    int     h;
    int     x;

	ray.raydirx = 0;
    w = all->info->res_x;
    h = all->info->res_y;
    x = 0;
    while (x < w)
    {
        ft_init_ray(&ray);
		all->info->mapy = (int)all->info->pos_y;
		all->info->mapx = (int)all->info->pos_x;
		ray.camx = 2 * x / w - 1;
		ray.raydirx = all->info->dirx + all->info->planex * ray.camx;
		ray.raydiry = all->info->diry + all->info->planey * ray.camx;
		ray.deltadistx = fabs(1 / ray.raydirx);
		ray.deltadisty = fabs(1 / ray.raydiry);
		ray.stepx = (ray.raydirx < 0) ? -1 : 1;
		ray.sidedistx = (ray.raydirx < 0) ?
		(all->info->pos_x - all->info->mapx) * ray.deltadistx : (all->info->mapx + 1.0 - all->info->pos_x) * ray.deltadistx;
		ray.stepy = (ray.raydiry < 0) ? -1 : 1;
		ray.sidedisty = (ray.raydiry < 0) ? (all->info->pos_y - all->info->mapy) * ray.deltadisty : (all->info->mapy + 1.0 - all->info->pos_y) * ray.deltadisty;
		ray.hit = 0;

		
		while (ray.hit == 0)
		{
			if (ray.sidedistx < ray.sidedisty)
			{
				ray.sidedistx += ray.deltadistx;
				all->info->mapx += +ray.stepx;
				ray.side = 0;
			}
			else
			{
				ray.sidedisty += ray.deltadisty;
				all->info->mapy += ray.stepy;
				ray.side = 1;
			}
			if (all->info->map[(int)all->info->mapy][(int)all->info->mapx] != '0')
				ft_check_hit(all, &ray);
			if (ray.side == 0)
				ray.perpwalldist = (all->info->mapx - all->info->pos_x + (1 - ray.stepx) / 2) / ray.raydirx;
			else
				ray.perpwalldist = (all->info->mapy - all->info->pos_y + (1 - ray.stepy) / 2) / ray.raydiry;
		}

		ray.lineh = (all->info->res_y / ray.perpwalldist);
		ray.drawst = -ray.lineh / 2 + h / 2;
		ray.drawend = ray.lineh / 2 + h / 2;
		if (ray.drawst < 0)
			ray.drawst = 0;
		if (ray.drawend >= h)
			ray.drawend = h - 1;

		if (ray.side == 0)
			ray.wallx = all->info->pos_y + ray.perpwalldist * ray.raydiry;
		else
			ray.wallx = all->info->pos_x + ray.perpwalldist * ray.raydirx;
		ray.wallx -= floor(ray.wallx);

		ray.texx = ray.wallx * all->img->textw[1];
		if (ray.side == 0 && ray.raydirx > 0)
			ray.texx = all->img->textw[1] - ray.texx - 1;
		if (ray.side == 1 && ray.raydiry < 0)
			ray.texx = all->img->textw[1] - ray.texx - 1;
		ray.side = ray.stepx > 0 && ray.side == 0 ? 3 : ray.side;
		ray.side = ray.stepy > 0 && all->info->mapy - all->info->pos_y > 0 && ray.side == 1 ? 4 : ray.side;
		ray.step = 1.0 * all->img->texth[sidetext(ray)] / ray.lineh;
		ray.texpos = (ray.drawst - all->info->res_y / 2 + ray.lineh / 2) * ray.step;
		vect.y = 0;
		vect.x = x;
		
		while (vect.y < ray.drawst)
		{
			my_put_pixel(all, vect.x, vect.y, all->img->crgb);
			vect.y++;
		}
		while (vect.y < ray.drawend)
		{
			ray.texy = (int)ray.texpos;
			ray.texpos = ray.texpos + ray.step;
			ft_put_pixeltex(all, ray, vect, sidetext(ray));
			vect.y++;
		}
		while (vect.y < all->info->res_y)
		{
			my_put_pixel(all, vect.x, vect.y, all->img->frgb);
			vect.y++;
		}
        x++;
    }
	ft_init_direction(all);
    return (0);
}