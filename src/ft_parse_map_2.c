/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:37:13 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/23 11:47:07 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strlcpy_fill_map(const char *src, char *dest, size_t dstsize)
{
	size_t	a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	while (a < dstsize)
	{
		dest[a] = ' ';
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

t_info	ft_get_map(t_info info, int fd)
{
	info.i = 0;
	info.map = ft_calloc(info.maplen * 2, sizeof(char *));
	if (!info.map)
	{
		info.v = 0;
		return (info);
	}
	while (info.i < info.maplen)
	{
		info.map[info.i] = malloc(sizeof(char *) * info.mapsize * 2);
		if (!info.map[info.i])
		{
			info.v = 0;
			return (info);
		}
		info.map[info.i] = ft_strlcpy_fill_map(info.buff,
			info.map[info.i], info.mapsize);
		info.i++;
		free(info.buff);
		get_next_line(fd, &info.buff);
	}
	free(info.buff);
	get_next_line(fd, &info.buff);
	return (info);
}
