/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:51:47 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/26 22:34:21 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_check_hit(t_all *all, t_ray *ray)
{
	if (all->info->map[(int)all->info->mapy][(int)all->info->mapx] == '2')
		ft_chek_number_sprite(all);
	if (all->info->map[(int)all->info->mapy][(int)all->info->mapx] == '1')
		ray->hit = 1;
	return (0);
}

void	ft_perp_calcul(t_all *all, t_ray *ray, t_indic *indic)
{
	ray->lineh = (all->info->res_y / ray->perpwalldist);
	ray->drawst = -ray->lineh / 2 + indic->h / 2;
	ray->drawend = ray->lineh / 2 + indic->h / 2;
	if (ray->drawst < 0)
		ray->drawst = 0;
	if (ray->drawend >= indic->h)
		ray->drawend = indic->h - 1;
	if (ray->side == 0)
		ray->wallx = all->info->pos_y + ray->perpwalldist * ray->raydiry;
	else
		ray->wallx = all->info->pos_x + ray->perpwalldist * ray->raydirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = ray->wallx * all->img->textw[1];
	if (ray->side == 0 && ray->raydirx > 0)
		ray->texx = all->img->textw[1] - ray->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texx = all->img->textw[1] - ray->texx - 1;
	if (ray->stepx > 0 && ray->side == 0)
		ray->side = 3;
	if (ray->stepy > 0 && all->info->mapy - all->info->pos_y > 0 &&
			ray->side == 1)
		ray->side = 4;
	ray->step = 1.0 * all->img->texth[ft_check_tex_view(ray)] / ray->lineh;
}

void	ft_wall_calcul(t_all *all, t_ray *ray, t_indic *indic)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			all->info->mapx += +ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			all->info->mapy = all->info->mapy + ray->stepy;
			ray->side = 1;
		}
		if (all->info->map[(int)all->info->mapy][(int)all->info->mapx] != '0')
			ft_check_hit(all, ray);
	}
	if (ray->side == 0)
		ray->perpwalldist = (all->info->mapx -
		all->info->pos_x + (1 - ray->stepx) / 2) / ray->raydirx;
	else
		ray->perpwalldist = (all->info->mapy -
		all->info->pos_y + (1 - ray->stepy) / 2) / ray->raydiry;
	ft_perp_calcul(all, ray, indic);
}

void	ft_direction(t_all *all, t_ray *ray, t_indic *indic)
{
	all->info->mapy = (int)all->info->pos_y;
	all->info->mapx = (int)all->info->pos_x;
	ray->camx = 2 * indic->x / indic->w - 1;
	ray->raydirx = all->info->dirx + all->info->planex * ray->camx;
	ray->raydiry = all->info->diry + all->info->planey * ray->camx;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->stepx = (ray->raydirx < 0) ? -1 : 1;
	if (ray->raydirx < 0)
		ray->sidedistx = (all->info->pos_x - all->info->mapx) *
		ray->deltadistx;
	else
		ray->sidedistx = (all->info->mapx + 1.0 - all->info->pos_x) *
		ray->deltadistx;
	if (ray->raydiry < 0)
		ray->stepy = -1;
	else
		ray->stepy = 1;
	if (ray->raydiry < 0)
		ray->sidedisty = (all->info->pos_y - all->info->mapy) * ray->deltadisty;
	else
		ray->sidedisty = (all->info->mapy + 1.0 - all->info->pos_y) *
		ray->deltadisty;
	ft_wall_calcul(all, ray, indic);
}

int		ft_ray(t_all *all)
{
	t_ray	ray;
	t_vect	vect;
	t_indic	indic;

	ray.raydirx = 0;
	indic.w = all->info->res_x;
	indic.h = all->info->res_y;
	indic.x = 0;
	while (indic.x < indic.w)
	{
		ft_init_ray(&ray);
		ft_direction(all, &ray, &indic);
		ft_my_put_pixel(all, &ray, &vect, indic.x);
		all->sprite->buffz[indic.x] = ray.perpwalldist;
		indic.x++;
	}
	if (all->sprite->count > 0)
		ft_sprite_calcul(all, &ray, indic.w, indic.h);
	ft_init_direction(all);
	return (0);
}
