/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:57 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/28 17:17:25 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char		*ft_strdel(char *s)
{
	if (s != NULL)
	{
		s = NULL;
		free(s);
		s = NULL;
	}
	return (s);
}

void		ft_destroy_map(t_info *info)
{
	int i;

	i = 0;
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

void		ft_destroy_img(t_all *all)
{
	int i;

	mlx_destroy_image(all->game->mlx, all->img->img);
	i = 0;
	while (all->img->addr[i])
	{
		all->img->addr[i] = NULL;
		free(all->img->addr[i]);
		i++;
	}
}
t_info		*ft_destroy_info(t_info *info)
{
	ft_strdel(info->texture_n);
	ft_strdel(info->texture_w);
	ft_strdel(info->texture_e);
	ft_strdel(info->texture_s);
	ft_strdel(info->texture_sprite);
	ft_destroy_map(info);
	return (info);
}

int			ft_destroy_all(t_all *all)
{
	ft_destroy_info(all->info);
	ft_destroy_img(all);
	return (0);
}
