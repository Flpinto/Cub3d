/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:37:13 by flpinto           #+#    #+#             */
/*   Updated: 2020/11/09 08:43:43 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_info      ft_get_map(t_info info, int fd)
{
    info.i = 0;
    
    if (!(info.map = malloc(sizeof(char *) * info.maplen)))
    {
        info.v = 0;
        printf("ERRORO MALLOC MAP\n");
        return (info);
    }
    while (info.i < info.maplen)
    {
        info.map[info.i] = ft_strdup(info.buff);
        info.i++;
        get_next_line(fd, &info.buff);
    }
    ft_strlcpy(info.map[info.i], info.buff, info.mapsize);
    get_next_line(fd, &info.buff);
    return (info);
}