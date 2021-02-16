/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/02 13:46:22 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_check_extension(char *filemap)
{
	int i;

	i = ft_strlen(filemap);
	if (ft_strncmp((filemap + i - 4), ".cub", i))
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_info	info;
	t_all	all;

	if (argc == 1)
	{
		write(1, "no map\n", 7);
		exit(0);
	}
	info = ft_parse_info((char *)argv[1], info);
	all.info = &info;
	ft_check_map(&info);
	all = ft_run_game(all, argc, argv[2]);
	return (0);
}
