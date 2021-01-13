/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:37:13 by flpinto           #+#    #+#             */
/*   Updated: 2020/12/04 17:26:29 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_info      ft_get_map(t_info info, int fd)
{
    info.i = 0;
    
    if (!(info.map = malloc(sizeof(char *) * info.maplen + 1)))
    {
        info.v = 0;
        write(1, "ERRORO MALLOC MAP\n", 18);
        return (info);
    }
    while (info.i < info.maplen)
    {
        info.map[info.i] = ft_strdup(info.buff);
        info.i++;
        free(info.buff);
        get_next_line(fd, &info.buff);
    }
    ft_strlcpy(info.map[info.i], info.buff, info.mapsize);
    free(info.buff);
    get_next_line(fd, &info.buff);
    return (info);
}
