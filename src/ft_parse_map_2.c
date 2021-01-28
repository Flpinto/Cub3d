/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:37:13 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/25 15:05:04 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strlcpy_fill_map(const char *src, size_t dstsize)
{
	size_t	a;
	char	*dest;
	a = 0;
	if (!src)
		return (NULL);
	if (dstsize > 0)
	{
		dest = malloc(sizeof(char *) * dstsize);
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
	}
	return (dest);
}

t_info	ft_get_map(t_info info, int fd)
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
		info.map[info.i] = ft_strlcpy_fill_map(info.buff, info.mapsize);
		info.i++;
		free(info.buff);
		get_next_line(fd, &info.buff);
	}
	free(info.buff);
	get_next_line(fd, &info.buff);
	return (info);
}
