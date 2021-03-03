/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:56:06 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/03 10:53:58 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_end_pre(t_info *info)
{
	ft_destroy_info(info);
	exit(0);
}

int			ft_check_pos(int stpos)
{
	if (stpos > 1 || stpos < 1)
	{
		write(1, "Error : Bad start-position\n", 27);
		return (-1);
	}
	return (0);
}

int			ft_check_arps(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0')
		return (1);
	return (0);
}

int			ft_check_around(int x, int y, t_info *info)
{
	if (x > 0)
		if (ft_check_arps(info->map[y][x + 1]) == 1 ||
		ft_check_arps(info->map[y][x - 1]) == 1)
			return (1);
	if (x == 0)
		if (ft_check_arps(info->map[y][x + 1]) == 1)
			return (1);
	if (y == 0)
		if (ft_check_arps(info->map[y + 1][x]) == 1)
			return (1);
	if (y + 1 == info->maplen)
		if (ft_check_arps(info->map[y - 1][x]) == 1)
			return (1);
	if (y > 0 && y + 1 < info->maplen)
		if (ft_check_arps(info->map[y + 1][x]) == 1 ||
		ft_check_arps(info->map[y - 1][x]) == 1)
			return (1);
	return (0);
}
