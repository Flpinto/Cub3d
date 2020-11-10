/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:37:16 by flpinto           #+#    #+#             */
/*   Updated: 2020/11/01 12:35:56 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     ft_free_tab(t_info *info)
{
    int i;

    i=0;
    while (info->tab[i++])
    {
        info->tab[i] = NULL;
        free(info->tab[i]);
    }
    info->tab = NULL;
    free(info->tab);
    return(0);
}

t_info      ft_get_color(t_info info, char c)
{

    info.tab = ft_split(info.buff + ++info.i, ',');
    if (!info.tab[2] || info.tab[3])
    {
        ft_free_tab(&info);
        info.v = 0;
        return (info);
    }
    if (c == 'F')
    {
        info.vf++;
        info.color_f[0] = ft_atoi(info.tab[0]);
        info.color_f[1] = ft_atoi(info.tab[1]);
        info.color_f[2] = ft_atoi(info.tab[2]);
    }
    if (c ==  'C')
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
t_info      ft_get_res(t_info info)
{
    info.i++;
    info.vr++;
    info.tab = ft_split(info.buff + info.i, ' ');
    if (!info.tab[1] || info.tab[2])
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