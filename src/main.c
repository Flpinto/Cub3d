/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/07 11:54:36 by flpinto          ###   ########.fr       */
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
		ft_putstr_fd("Error : No map", 1);
		return (0);
	}
	if ((argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0))
	{
		printf("Error : '%s' is not a valid argument.", argv[2]);
		return (0);
	}
	if (argc > 3)
	{
		ft_putstr_fd("Too many arguments\n", 1);
		return (0);
	}
	info = ft_parse_info((char *)argv[1], info);
	all.info = &info;
	ft_check_map(&info);
	all = ft_run_game(all, argc, argv[2]);
	return (0);
}
