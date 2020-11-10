/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:28:56 by flpinto           #+#    #+#             */
/*   Updated: 2020/11/04 17:54:43 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     ft_get_y_max(char **map)
{
    int i;

    i = 1;
    while (map[i])
        i++;
    return (i);
}
int     ft_check_map_char(t_info *info)
{
    int x;
    int y;
    int sp_direction;

    x = 0;
    y = 0;
    sp_direction = 0;
    while(info->map[y])
    {
        x = 0;
        while(info->map[y][x])
        {
            if (info->map[y][x] == 'N' || info->map[y][x] == 'W' || info->map[y][x] == 'S' ||  info->map[y][x] == 'E')
            {
                info->pos_x = x;
                info->pos_y = y;
                info->orient = info->map[y][x];
                sp_direction++;
            }
            if (info->map[y][x] == '1' || info->map[y][x] == '0' || info->map[y][x] == 32 || 
            info->map[y][x] == 'N' || info->map[y][x] == 'W' || info->map[y][x] == 'S' ||  info->map[y][x] == 'E' ||
            info->map[y][x] == '2')
                x++;
            else
            {
                printf("-----ERROR CHAR MAP -> %c <- INVALID-------\n", info->map[y][x]);
                return (-1);
            }
        }
        y++;
    }
    if (sp_direction != 1)
        return (-1);
    return (0);
}
int     ft_check_boarder(t_info *info)
{
    int x;
    int y;
    int y_max;

    x = 0;
    y = 0;
    y_max = ft_get_y_max(info->map);
    while(info->map[y])
    {
        x = 0;
        while(info->map[y][x])
        {
            while (info->map[y][x] == ' ')
                x++;
            if ((info->map[y][x] != '1' && info->map[y][x - 1] == ' ' && info->map[y][x + 1] != ' ') || 
            (info->map[y][x] != '1' && x == 0) || (info->map[y][x] != '1' && info->map[y][x + 1] == '\0'))
            {
                printf("Error Border %c isn't a border character", info->map[y][x]);
                return (-1);
            }
            else if ((y == y_max - 1 && info->map[y][x] != '1' && info->map[y][x] != ' ') ||
            (y == 1 && info->map[y][x] != '1' && info->map[y][x] != ' '))
            {
                printf("Error Border %c ", info->map[y][x]);
                return (-1);
            }
            else
                x++;         
        }
        y++;
    }
    return (0);
}
/*
int     ft_check_inside(char **map)
{
    int x;
    int y;

    x = 0;
    y = 1;
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == ' ' && (map[y][x - 1] == '0' || map[y][x + 1] == '0' ||
             map[y - 1][x] == '0' || map[y + 1][x] == '0'))
            {
                printf("Error!! --%d--- ---%d---- UPD Whole in the map", y, x);
                return (-1);
            }
            else
                x++;
        }
        y++;
    }
    return (0);
}
*/
t_info     ft_check_map(t_info info)
{
    ft_check_map_char(&info);
    ft_check_boarder(&info);
    if (info.v == -1)
        info.v = -1;
    return (info);
}