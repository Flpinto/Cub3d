/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 10:55:58 by flpinto           #+#    #+#             */
/*   Updated: 2020/06/07 12:46:07 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_get_color_c(char *mapline, t_info *color)
{
	mapline += 2;
		color->color_c[0] = ft_atoi(mapline);
		while(ft_isdigit(*mapline))
        	mapline++;
		mapline ++;
		color->color_c[1] = ft_atoi(mapline);
		while(ft_isdigit(*mapline))
        	mapline++;
		mapline ++;
		color->color_c[2] = ft_atoi(mapline);
		while(ft_isdigit(*mapline))
        	mapline++;
		color->color_c[3] = 0;
}

void	ft_get_color_f(char *mapline, t_info *color)
{
	mapline += 2;
		color->color_f[0] = ft_atoi(mapline);
		while(ft_isdigit(*mapline))
        	mapline++;
		mapline ++;
		color->color_f[1] = ft_atoi(mapline);
		while(ft_isdigit(*mapline))
        	mapline++;
		mapline ++;
		color->color_f[2] = ft_atoi(mapline);
		while(ft_isdigit(*mapline))
        	mapline++;
		color->color_f[3] = 0;
}

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
    while(ft_isdigit(*mapline))
        mapline++;
    res->res_y = ft_atoi(mapline);
}

t_info      *ft_parse_info(char *filemap)
{
	t_info  *infomap;
	char	*mapline[1024];
	int	 fd;
	int	 i;
	int	 j;

	j = 1;
	fd = open(filemap, O_RDONLY);
	infomap = ft_calloc(sizeof(t_info), 1);
	while ((i = get_next_line(fd, &mapline[j - 1])) > 0)
	{
		if (*mapline[j - 1] == 'F' || *mapline[j - 1] == 'C')
			ft_get_color(mapline[j - 1], infomap);
		if (*mapline[j - 1] == 'R')
			ft_get_res(mapline[j - 1], infomap);
		printf("%s\n", mapline[j - 1]); 
		j++;
	}
	printf("%s\n", mapline[j - 1]);	
	close(fd);
		
	while (--j > 0)
		free(mapline[j - 1]);
	return (infomap);
}