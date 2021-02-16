/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:57 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/01 18:43:39 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char		*ft_strdel(char *s)
{
	if (s != NULL)
	{
		free(s);
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

t_info		*ft_destroy_info(t_info *info)
{
	if (info->texture_n)
		free(info->texture_n);
	if (info->texture_w)
		free(info->texture_w);
	if (info->texture_e)
		free(info->texture_e);
	if (info->texture_s)
		free(info->texture_s);
	if (info->texture_sprite)
		free(info->texture_sprite);
	info->orient = 0;
	if (info->map)
		ft_destroy_map(info);
	return (info);
}

int			ft_destroy_all(t_all *all)
{
	ft_destroy_info(all->info);
	return (0);
}
