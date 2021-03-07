/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:37:16 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/03 15:42:30 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_check_is_numsp(char *s)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] == ' ' || ft_isdigit(s[j]) == 1 || s[j] == '\t')
			j++;
		else
			return (-1);
	}
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (ft_isdigit(s[i]) == 1)
		i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (i != j)
		return (-1);
	return (0);
}

int		ft_check_tab(char **tab)
{
	int y;

	y = 0;
	while (tab[y])
	{
		if (ft_check_is_numsp(tab[y]) == -1)
			return (-1);
		y++;
	}
	return (0);
}

t_info	ft_get_color_c(t_info info)
{
	info.tab = ft_split(info.buff + ++info.i, ',');
	if (!info.tab[2] || !info.tab[1] || info.tab[3] ||
	ft_check_tab(info.tab) == -1)
		return (ft_free_tab_c(info));
	info.vc++;
	if (info.vc > 1 || ft_atoi(info.tab[0]) > 255 ||
	ft_atoi(info.tab[1]) > 255 || ft_atoi(info.tab[2]) > 255)
	{
		ft_putstr_fd("Error : To many C or RGB code not valid\n", 1);
		return (ft_free_tab_c(info));
	}
	info.color_c[0] = ft_atoi(info.tab[0]);
	info.color_c[1] = ft_atoi(info.tab[1]);
	info.color_c[2] = ft_atoi(info.tab[2]);
	ft_free_tab(&info);
	info.vall++;
	info.i = 0;
	return (info);
}

t_info	ft_get_color_f(t_info info)
{
	info.tab = ft_split(info.buff + ++info.i, ',');
	if (!info.tab[2] || !info.tab[1] || info.tab[3] ||
	ft_check_tab(info.tab) == -1)
		return (ft_free_tab_c(info));
	info.vf++;
	if (info.vf > 1 || ft_atoi(info.tab[0]) > 255 ||
	ft_atoi(info.tab[1]) > 255 || ft_atoi(info.tab[2]) > 255)
	{
		ft_putstr_fd("Error : To many F or RGB code not valid\n", 1);
		return (ft_free_tab_c(info));
	}
	info.color_f[0] = ft_atoi(info.tab[0]);
	info.color_f[1] = ft_atoi(info.tab[1]);
	info.color_f[2] = ft_atoi(info.tab[2]);
	ft_free_tab(&info);
	info.vall++;
	info.i = 0;
	return (info);
}

t_info	ft_get_res(t_info info)
{
	info.i++;
	info.vr++;
	info.tab = ft_split(info.buff + info.i, ' ');
	if (!info.tab[0] || !info.tab[1] || info.tab[2] ||
	ft_check_tab(info.tab) == -1)
	{
		ft_free_tab(&info);
		ft_putstr_fd("Error : Resolution Not Valid\n", 1);
		info.v = 0;
		return (info);
	}
	if (ft_atoi(info.tab[0]) < 1 || ft_atoi(info.tab[1]) < 1)
	{
		ft_free_tab(&info);
		ft_putstr_fd("Error : Resolution Can not be negative or null\n", 1);
		info.v = 0;
		return (info);
	}
	info.res_x = ft_atoi(info.tab[0]);
	info.res_y = ft_atoi(info.tab[1]);
	ft_free_tab(&info);
	info.i = 0;
	info.vall++;
	return (info);
}
