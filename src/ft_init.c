/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:42:36 by flpinto           #+#    #+#             */
/*   Updated: 2020/12/08 12:09:44 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	truefilebf()
{
	write(1, "Textures goes wrong\n", 20);
	exit(0);
}

t_data      ft_get_img_by_file(t_data img, t_all all)
{
    int i;

    i = 0;
	img.addr[0] = mlx_get_data_addr(img.img[0], &img.bits_per_pixel[0], &img.line_length[0], &img.endian[0]);
    img.img[1] = mlx_xpm_file_to_image(all.game->mlx,
			all.info->texture_n, &img.textw[1], &img.texth[1]);
	img.img[2] = mlx_xpm_file_to_image(all.game->mlx,
			all.info->texture_s, &img.textw[2], &img.texth[2]);
	img.img[3] = mlx_xpm_file_to_image(all.game->mlx,
			all.info->texture_w, &img.textw[3], &img.texth[3]);
	img.img[4] = mlx_xpm_file_to_image(all.game->mlx,
			all.info->texture_e, &img.textw[4], &img.texth[4]);
	img.img[5] = mlx_xpm_file_to_image(all.game->mlx,
			all.info->texture_sprite ,&img.textw[5], &img.texth[5]);
    while (i++ <= 5)
		(img.img[i] == 0) ? truefilebf() : 0;
	img.frgb = 65536 * all.info->color_f[0] + 256 * all.info->color_f[1] + all.info->color_f[2];
	img.crgb = 65536 * all.info->color_c[0] + 256 * all.info->color_c[1] + all.info->color_c[2];
    return (img);
}