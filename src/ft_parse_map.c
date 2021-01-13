/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:03:59 by flpinto           #+#    #+#             */
/*   Updated: 2020/12/04 17:25:29 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
int      ft_check_line_map(t_info info)
{
    int len;
    int count;

    len = 0;
    count = 0;
    while (info.buff[len] == '1' || info.buff[len] == ' ')
	{
		if (info.buff[len] == '1')
			count = 1;
		len++;
	}
    if (count == 1)
        return (count);
    return (0); 
}
t_info      ft_return_to_map(t_info info, int fd, char *filemap)
{
    info.i = 0;
    fd = open(filemap, O_RDONLY);
    get_next_line(fd, &info.buff);
    while (ft_check_line_map(info) == 0)
    {
        info.i = 0;
		while (info.buff[info.i] == ' ')
		{
			if (info.buff[info.i + 1] == '1')
				return (info);
			info.i++;
		}
        free(info.buff);
        get_next_line(fd, &info.buff);  
    }
    info.i = 0;
    return (info);
}

t_info      ft_get_map_len(t_info info, int fd, char *filemap)
{
    while (info.buff[0] == '1' || info.buff[0] == ' ')
	{
		info.maplen++;
		info.i = 0;
		while (info.buff[info.i])
		{
			info.i++;
			if (info.i > info.mapsize)
                info.mapsize = info.i;
		}
		free(info.buff);
		info.end = get_next_line(fd, &info.buff);
	}
    free(info.buff);
    if (info.end != 0)
        info.v = 0;
    close(fd);
    info = ft_return_to_map(info, fd, filemap);
    info = ft_get_map(info, fd);
    return (info);
}
t_info      ft_parse_map(t_info info, int fd, char *filemap)
{
   
    if (info.maplen == 0)
        info = ft_get_map_len(info, fd, filemap);
    //ft_check_map(info);
    return (info);
}