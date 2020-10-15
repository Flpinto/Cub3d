/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:28:56 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/15 12:44:34 by flpinto          ###   ########.fr       */
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
int     ft_check_map_char(char **map, t_info *info)
{
    int x;
    int y;
    int sp_direction;

    x = 0;
    y = 2;
    sp_direction = 0;
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'S' ||  map[y][x] == 'E')
            {
                info->pos_x = x;
                info->pos_y = y;
                info->orient = map[y][x];
                sp_direction++;
            }
            if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 32 || 
            map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'S' ||  map[y][x] == 'E' ||
            map[y][x] == '2')
                x++;
            else
            {
                printf("-----ERROR CHAR MAP -> %c <- INVALID-------\n", map[y][x]);
                return (-1);
            }
        }
        y++;
    }
    if (sp_direction != 1)
        return (-1);
    return (0);
}
int     ft_check_boarder(char **map)
{
    int x;
    int y;
    int y_max;

    x = 0;
    y = 1;
    y_max = ft_get_y_max(map);
    while(map[y])
    {
        x = 0;
        while(map[y][x])
        {
            while (map[y][x] == ' ')
                x++;
            if ((map[y][x] != '1' && map[y][x - 1] == ' ' && map[y][x + 1] != ' ') || 
            (map[y][x] != '1' && x == 0) || (map[y][x] != '1' && map[y][x + 1] == '\0'))
            {
                printf("Error Border %c isn't a border character", map[y][x]);
                return (-1);
            }
            else if ((y == y_max - 1 && map[y][x] != '1' && map[y][x] != ' ') ||
            (y == 1 && map[y][x] != '1' && map[y][x] != ' '))
            {
                printf("Error Border %c ", map[y][x]);
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
int     ft_check_map(char **map, t_info *info)
{
    if (ft_check_map_char(map, info) == -1 || ft_check_boarder(map) == -1 )
        return (-1);
    return (0);
}