/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:27:40 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/05 12:15:03 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char		*file_header_bmp(int size, t_all *all)
{
	char	*fileheader;

	if (!(fileheader = (char*)malloc(14 * sizeof(char))))
	{
		write(1, "error malloc\n", 11);
		ft_destroy_all(all);
		exit(0);
	}
	ft_memcpy(fileheader, (char[]) {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54,
			0, 0, 0}, 14);
	fileheader[2] = (char)(size);
	fileheader[3] = (char)(size >> 8);
	fileheader[4] = (char)(size >> 16);
	fileheader[5] = (char)(size >> 24);
	return (fileheader);
}

char		*info_header_bmp(t_all *all)
{
	char	*infoheader;

	if (!(infoheader = (char*)malloc(40 * sizeof(char))))
	{
		write(1, "error malloc\n", 11);
		ft_destroy_all(all);
		exit(0);
	}
	ft_memcpy(infoheader, (char[]) {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0}, 40);
	infoheader[4] = (char)(all->info->res_x);
	infoheader[5] = (char)(all->info->res_x >> 8);
	infoheader[6] = (char)(all->info->res_x >> 16);
	infoheader[7] = (char)(all->info->res_x >> 24);
	infoheader[8] = (char)(all->info->res_y);
	infoheader[9] = (char)(all->info->res_y >> 8);
	infoheader[10] = (char)(all->info->res_y >> 16);
	infoheader[11] = (char)(all->info->res_y >> 24);
	return (infoheader);
}

void		write_data(int f, char *data, t_all *all)
{
	int				line;

	line = all->info->res_y;
	while (--line + 1)
		write(f, data + all->info->res_x * line * 4, all->info->res_x * 4);
}

void		ft_save(char *data, t_all *all, int ac, char *av)
{
	int				size;
	int				f;
	char			*fileheader;
	char			*infoheader;

	if (ac == 3 && ft_strncmp(av, "--save", 6) == 0)
	{
		size = 14 + 40 + 3 * all->info->res_x * all->info->res_y;
		f = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
		fileheader = file_header_bmp(size, all);
		write(f, fileheader, 14);
		free(fileheader);
		infoheader = info_header_bmp(all);
		write(f, infoheader, 40);
		free(infoheader);
		write_data(f, data, all);
		close(f);
		ft_destroy_all(all);
		exit(0);
	}
}
