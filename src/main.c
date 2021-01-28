/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/25 15:42:34 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		main(int argc, const char **argv)
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
	all = ft_run_game(all);
	ft_destroy_all(&all);
	return (0);
}
