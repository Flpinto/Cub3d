/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:18:08 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/23 12:56:17 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_info	ft_parse_s(t_info info)
{
	if (info.vso == 1)
	{
		info.v = 0;
		write(1, "too much S \n", 13);
		return (info);
	}
	info.vso++;
	info.i += 2;
	while (info.buff[info.i] == ' ' || info.buff[info.i] == '\t')
		info.i++;
	info.texture_s = ft_strdup(info.buff + info.i);
	if (open(info.texture_s, O_RDONLY) == -1)
	{
		write(1, "Dumb sp path\n", 13);
		info.v = 0;
	}
	info.i = 0;
	info.vall++;
	return (info);
}

t_info	ft_parse_n(t_info info)
{
	if (info.vno == 1)
	{
		info.v = 0;
		write(1, "too much S \n", 13);
		return (info);
	}
	info.vno++;
	info.i += 2;
	while (info.buff[info.i] == ' ' || info.buff[info.i] == '\t')
		info.i++;
	info.texture_n = ft_strdup(info.buff + info.i);
	if (open(info.texture_n, O_RDONLY) == -1)
	{
		write(1, "Dumb sp path\n", 13);
		info.v = 0;
	}
	info.i = 0;
	info.vall++;
	return (info);
}

t_info	ft_parse_e(t_info info)
{
	if (info.vea == 1)
	{
		info.v = 0;
		write(1, "too much S \n", 13);
		return (info);
	}
	info.vea++;
	info.i += 2;
	while (info.buff[info.i] == ' ' || info.buff[info.i] == '\t')
		info.i++;
	info.texture_e = ft_strdup(info.buff + info.i);
	if (open(info.texture_e, O_RDONLY) == -1)
	{
		write(1, "Dumb sp path\n", 13);
		info.v = 0;
	}
	info.i = 0;
	info.vall++;
	return (info);
}

t_info	ft_parse_w(t_info info)
{
	if (info.vwe == 1)
	{
		info.v = 0;
		write(1, "too much S \n", 13);
		return (info);
	}
	info.vwe++;
	info.i += 2;
	while (info.buff[info.i] == ' ' || info.buff[info.i] == '\t')
		info.i++;
	info.texture_w = ft_strdup(info.buff + info.i);
	if (open(info.texture_w, O_RDONLY) == -1)
	{
		write(1, "Dumb sp path\n", 13);
		info.v = 0;
	}
	info.i = 0;
	info.vall++;
	return (info);
}

t_info	ft_parse_sprite(t_info info)
{
	if (info.vsp == 1)
	{
		info.v = 0;
		write(1, "too much S \n", 13);
		return (info);
	}
	info.vsp++;
	info.i += 2;
	while (info.buff[info.i] == ' ' || info.buff[info.i] == '\t')
		info.i++;
	info.texture_sprite = ft_strdup(info.buff + info.i);
	if (open(info.texture_sprite, O_RDONLY) == -1)
	{
		write(1, "Dumb sp path\n", 13);
		info.v = 0;
	}
	info.i = 0;
	info.vall++;
	return (info);
}
