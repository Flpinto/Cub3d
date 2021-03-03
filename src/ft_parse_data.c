/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:37:16 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/03 10:46:12 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_free_tab(t_info *info)
{
	int i;

	i = 0;
	while (info->tab[i])
	{
		free(info->tab[i]);
		i++;
	}
	free(info->tab);
	return (0);
}

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

t_info	ft_get_color(t_info info, char c)
{
	info.tab = ft_split(info.buff + ++info.i, ',');
	if (!info.tab[2] || !info.tab[1] || info.tab[3] ||
	ft_check_tab(info.tab) == -1)
		return (ft_free_tab_c(info));
	if (c == 'F')
	{
		info.vf++;
		info.color_f[0] = ft_atoi(info.tab[0]);
		info.color_f[1] = ft_atoi(info.tab[1]);
		info.color_f[2] = ft_atoi(info.tab[2]);
	}
	if (c == 'C')
	{
		info.vc++;
		info.color_c[0] = ft_atoi(info.tab[0]);
		info.color_c[1] = ft_atoi(info.tab[1]);
		info.color_c[2] = ft_atoi(info.tab[2]);
	}
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
