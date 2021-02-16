/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:27:40 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/16 09:38:38 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char		*file_header_bmp(int filesize, t_all *all)
{
	char	*bmpfileheader;

	if (!(bmpfileheader = (char*)malloc(14 * sizeof(char))))
	{
		write(1, "error malloc\n", 11);
		ft_destroy_all(all);
		exit(0);
	}
	ft_memcpy(bmpfileheader, (char[]) {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54,
			0, 0, 0}, 14);
	bmpfileheader[2] = (char)(filesize);
	bmpfileheader[3] = (char)(filesize >> 8);
	bmpfileheader[4] = (char)(filesize >> 16);
	bmpfileheader[5] = (char)(filesize >> 24);
	return (bmpfileheader);
}

char		*info_header_bmp(t_all *all)
{
	char	*bmpinfoheader;

	if (!(bmpinfoheader = (char*)malloc(40 * sizeof(char))))
	{
		write(1, "error malloc\n", 11);
		ft_destroy_all(all);
		exit(0);
	}
	ft_memcpy(bmpinfoheader, (char[]) {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
			0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0}, 40);
	bmpinfoheader[4] = (char)(all->info->res_x);
	bmpinfoheader[5] = (char)(all->info->res_x >> 8);
	bmpinfoheader[6] = (char)(all->info->res_x >> 16);
	bmpinfoheader[7] = (char)(all->info->res_x >> 24);
	bmpinfoheader[8] = (char)(all->info->res_y);
	bmpinfoheader[9] = (char)(all->info->res_y >> 8);
	bmpinfoheader[10] = (char)(all->info->res_y >> 16);
	bmpinfoheader[11] = (char)(all->info->res_y >> 24);
	return (bmpinfoheader);
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
	int				filesize;
	int				f;
	char			*bmpfileheader;
	char			*bmpinfoheader;

	if (ac == 3 && ft_strncmp(av, "--save", 6) == 0)
	{
		filesize = 14 + 40 + 3 * all->info->res_x * all->info->res_y;
		f = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
		bmpfileheader = file_header_bmp(filesize, all);
		write(f, bmpfileheader, 14);
		free(bmpfileheader);
		bmpinfoheader = info_header_bmp(all);
		write(f, bmpinfoheader, 40);
		free(bmpinfoheader);
		write_data(f, data, all);
		close(f);
		ft_destroy_all(all);
		exit(0);
	}
}