/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 10:55:58 by flpinto           #+#    #+#             */
/*   Updated: 2020/08/27 14:34:22 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"



void		ft_get_color(char *mapline, t_info *color)
{
	if (*mapline == 'F')
		ft_get_color_f(mapline, color);
	if (*mapline == 'C')
		ft_get_color_c(mapline, color);

}

void		ft_get_res(char *mapline, t_info *res)
{
    mapline += 2;
    res->res_x = ft_atoi(mapline);
	if (res->res_x > 1920)
		res->res_x = 1920;
    while(ft_isdigit(*mapline))
        mapline++;
    res->res_y = ft_atoi(mapline);
	if (res->res_y > 1080)
		res->res_y = 1080;
}

int    ft_get_map(char *mapline, t_info *map)
{
    static int  mapst;
    if (map->res_x && map->res_y  && map->texture_e 
		&& map->texture_n && map->texture_w 
		&& map->texture_s && map->color_c[0] && map->color_f[0])
        {
            if(mapline)
            {
                map->map[mapst] = ft_strdup(mapline);
                mapst++;
            }  
        }
	return (0);
}

t_info      *ft_parse_info(char *filemap)
{
	t_info  *infomap;
	char	*mapline[1024];
	int	 fd;
	int	 i;
	int	 j;

	j = 0;
	fd = open(filemap, O_RDONLY);
	infomap = ft_calloc(sizeof(t_info), 1);
	infomap->map = malloc(sizeof(char*) * 1024);
	while ((i = get_next_line(fd, &mapline[j])) > 0)
	{
		if (*mapline[j] == 'F' || *mapline[j] == 'C')
			ft_get_color(mapline[j], infomap);
		if (*mapline[j] == 'R')
			ft_get_res(mapline[j], infomap);
		if (*mapline[j] == 'N' || (*mapline[j] == 'S' 
		|| (*mapline[j] == 'W' || (*mapline[j] == 'E'))))
			ft_get_textures(mapline[j], infomap);
		
		ft_get_map(mapline[j], infomap);
		j++;
	}
	ft_get_map(mapline[j], infomap);
	close(fd);
	while (j-- > 0)
		free(mapline[j]);
	return (infomap);
}