/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:28:56 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/28 15:55:58 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
				printf("Error : -%c- Wrong map character\n", info->map[y][x]);
			x++;
		}
		y++;
	}
	if (stpos > 1)
		printf("Error : multiple start-position\n");
	if (stpos < 1)
		printf("Error : no start-position\n");
	return (0);
}

void		ft_error_hole(void)
{
	printf("Error : Dangerous void in map\n");
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
			if (info->map[y][x] == ' ' && ((info->map[y][x + 1] != '1' || info->map[y][x + 1] != ' ') && (info->map[y][x - 1] != '1' || info->map[y][x - 1] != ' ')))
			{
				ft_error_hole();
				return (-1);
			}/*
			if (info->map[y][x] == ' ' && ((info->map[y + 1][x] != '1' || info->map[y + 1][x] != ' ') && (info->map[y - 1][x] != '1' || info->map[y - 1][x] != ' ')))
			{
				ft_error_hole();
				return (-1);
			}*/
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
			if ((y == 0 || y == info->maplen - 1) && (info->map[y][x] != '1' && info->map[y][x] != ' '))
			{
				ft_error_wall_border();
				return (-1);
			}
			if ((x == 0 || x == info->mapsize - 1) &&
			(info->map[y][x] != '1' && info->map[y][x] != ' '))
			{
				ft_error_wall_border();
				return (-1);
			}
			if (((x == 0 && info->map[y][x] == ' ' && (info->map[y][x + 1] != '1' && info->map[y][x + 1] != ' '))) ||
			(((x == info->mapsize - 1 && info->map[y][x] == ' ' && info->map[y][x - 1] != '1'))))
			{
				ft_error_wall_border();
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_check_map(t_info *info)
{
	ft_check_map_char(info);
	ft_check_boarder(info);
	ft_check_inside_map(info);

	//int i = 0;
	//while (info->map[i])
	//{
	//	printf("-%s-\n", info->map[i]);
	//	i++;
	//}
}