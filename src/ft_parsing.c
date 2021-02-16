/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 10:55:58 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/01 15:34:13 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			ft_check_sp(t_info info, int y)
{
	if (info.buff[info.i + y] == ' ' || info.buff[info.i + y] == '\t')
		return (1);
	return (0);
}

int			ft_init_validator(t_info *info)
{
	info->vno = 0;
	info->vso = 0;
	info->vwe = 0;
	info->vea = 0;
	info->vsp = 0;
	info->vs = 0;
	info->vf = 0;
	info->vc = 0;
	info->vr = 0;
	info->v = 2;
	info->vall = 0;
	info->maplen = 0;
	info->mapsize = 0;
	info->tab = NULL;
	return (0);
}

t_info		ft_check_data(t_info info, int fd, char *filemap)
{
	if (info.buff[info.i] == 'R' && ft_check_sp(info, 1) == 1)
		return (ft_get_res(info));
	if ((info.buff[info.i] == 'F' || info.buff[info.i] == 'C') &&
			ft_check_sp(info, 1) == 1)
		return (ft_get_color(info, info.buff[info.i]));
	if (info.buff[info.i] == 'S' && ft_check_sp(info, 1) == 1)
		return (ft_parse_sprite(info));
	if (info.buff[info.i] == 'N' && info.buff[info.i + 1] == 'O' &&
			ft_check_sp(info, 2) == 1)
		return (ft_parse_n(info));
	if (info.buff[info.i] == 'S' && info.buff[info.i + 1] == 'O' &&
			ft_check_sp(info, 2) == 1)
		return (ft_parse_s(info));
	if (info.buff[info.i] == 'W' && info.buff[info.i + 1] == 'E' &&
			ft_check_sp(info, 2) == 1)
		return (ft_parse_w(info));
	if (info.buff[info.i] == 'E' && info.buff[info.i + 1] == 'A' &&
			ft_check_sp(info, 2) == 1)
		return (ft_parse_e(info));
	if (info.v == 2 && info.vall == 8)
		return (ft_parse_map(info, fd, filemap));
	return (info);
}

t_info		ft_parse(int fd, t_info info, char *filemap)
{
	info.i = 0;
	info.end = 1;
	while (info.end == 1 && info.v != 0)
	{
		info.end = get_next_line(fd, &info.buff);
		if (info.buff[info.i] && info.end == 1)
		{
			while (info.buff[info.i] == ' ' || info.buff[info.i] == '\t')
				info.i++;
			info = ft_check_data(info, fd, filemap);
			free(info.buff);
		}
		else
			free(info.buff);
	}
	if (info.v == 0)
	{
		write(1, "Error parsing\n", 14);
		ft_destroy_info(&info);
		close(fd);
		exit(0);
	}
	return (info);
}

t_info		ft_parse_info(char *filemap, t_info info)
{
	int	fd;

	info.end = 0;
	fd = open(filemap, O_RDONLY);
	if (fd == -1 || ft_check_extension(filemap) == -1)
	{
		write(1, "Error file\n", 11);
		exit(0);
	}
	ft_init_validator(&info);
	info = ft_parse(fd, info, filemap);
	close(fd);
	return (info);
}
