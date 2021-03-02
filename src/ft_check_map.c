/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:28:56 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/02 21:47:05 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

int			ft_check_map_char(t_info *info)
{
	int x;
	int y;
	int stpos;

	y = 0;
	stpos = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (ft_check_stpos(info->map[y][x]) == 1)
				stpos++;
			if (ft_check_char(info->map[y][x]) != 1)
				return (ft_error_char());
			if (info->map[y][x] == ' ' && x < info->mapsize - 1 && ft_check_around(x, y, info) == 1)
				return (ft_error_hole());
			if (info->map[y][x] == ' ')
				info->map[y][x] = '1';
			x++;
		}
		y++;
	}
	if (ft_check_pos(stpos) == -1)
		return (-1);
	return (0);
}

int			ft_check_inside_map(t_info *info)
{
	int x;
	int y;

	y = 1;
	while (info->map[y] && y < info->maplen - 1)
	{
		x = 1;
		while (info->map[y][x] && x < info->mapsize - 1)
		{
			if (info->map[y][x] == ' ' && ((info->map[y][x + 1] != '1' &&
			info->map[y][x + 1] != ' ') && (info->map[y][x - 1] != '1' &&
			info->map[y][x - 1] != ' ')))
				return (ft_error_hole());
			if (info->map[y][x] == ' ' && ((info->map[y + 1][x] != '1' &&
			info->map[y + 1][x] != ' ') && (info->map[y - 1][x] != '1' &&
			info->map[y - 1][x] != ' ')))
				return (ft_error_hole());
			x++;
		}
		y++;
	}
	return (0);
}

int			ft_check_boarder(t_info *info)
{
	int x;
	int y;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if ((y == 0 || y == info->maplen - 1) && (info->map[y][x] != '1' &&
			info->map[y][x] != ' '))
				return (ft_error_wall_border());
			if ((x == 0 || x == info->mapsize - 1) && info->map[y][x] != '1' &&
			info->map[y][x] != ' ')
				return (ft_error_wall_border());
			x++;
		}
		y++;
	}
	return (0);
}

int			ft_check_map(t_info *info)
{

	
	if (!info->map)
	{
		write(1, "Error parsing\n", 14);
		ft_end_pre(info);
	}
	if (ft_check_map_char(info) == -1)
		ft_end_pre(info);
	if (ft_check_boarder(info) == -1)
		ft_end_pre(info);
	if (ft_check_inside_map(info) == -1)
		ft_end_pre(info);
	return (0);
}
