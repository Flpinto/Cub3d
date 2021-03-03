/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:42:36 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/03 10:56:31 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_error_text(void)
{
	write(1, "Error : Texture not valid\n", 20);
	exit(0);
}

void		ft_init_sprite(t_all *all)
{
	int i;

	i = 0;
	while (i < SPRITE)
	{
		all->sprite->x[i] = 0;
		all->sprite->y[i] = 0;
		all->sprite->distancex[i] = 0;
		all->sprite->distancey[i] = 0;
		all->sprite->distance[i] = 0;
		all->sprite->mat[i] = 0;
		all->sprite->tformx[i] = 0;
		all->sprite->tformy[i] = 0;
		all->sprite->order[i] = 0;
		all->sprite->count = 0;
		i++;
	}
	all->sprite->restart = SPRITE + 10;
}

int			ft_init_ray(t_ray *ray)
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

t_data		ft_get_img_by_file(t_data img, t_all all)
{
	int	i;

	i = 0;
	img.addr[0] = mlx_get_data_addr(img.img[0],
		&img.bits_per_pixel[0], &img.line_length[0], &img.endian[0]);
	img.img[1] = mlx_xpm_file_to_image(all.game->mlx,
		all.info->texture_n, &img.textw[1], &img.texth[1]);
	img.img[2] = mlx_xpm_file_to_image(all.game->mlx,
		all.info->texture_s, &img.textw[2], &img.texth[2]);
	img.img[3] = mlx_xpm_file_to_image(all.game->mlx,
		all.info->texture_w, &img.textw[3], &img.texth[3]);
	img.img[4] = mlx_xpm_file_to_image(all.game->mlx,
		all.info->texture_e, &img.textw[4], &img.texth[4]);
	img.img[5] = mlx_xpm_file_to_image(all.game->mlx,
		all.info->texture_sprite, &img.textw[5], &img.texth[5]);
	while (i++ <= 5)
		(img.img[i] == 0) ? ft_error_text() : 0;
	img.frgb = 65536 * all.info->color_f[0] + 256 *
		all.info->color_f[1] + all.info->color_f[2];
	img.crgb = 65536 * all.info->color_c[0] + 256 *
		all.info->color_c[1] + all.info->color_c[2];
	return (img);
}
