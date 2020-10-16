/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 10:55:58 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/16 14:56:07 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"



t_info		ft_parse(int fd, char *filemap, t_info info)
{
	while (info.end == 1)
	{
		info.end = get_next_line(fd, &info.buff)
	}
}

t_info      *ft_parse_info(char *filemap, t_info info)
{
	int	 fd;

	info.end = 1;
	fd = open(filemap, O_RDONLY);
	if (fd == -1)
	{
		write(1, "wrong files\n", 10);
		exit(0);
	}
	info = ft_parse(fd, filemap, info);
	close(fd);

	return (info);
}