/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:56:06 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/02 21:47:10 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_end_pre(t_info *info)
{
	ft_destroy_info(info);
	exit(0);
}

int			ft_check_pos(int stpos)
{
	if (stpos > 1 || stpos < 1)
	{
		write(1, "Error : Bad start-position\n", 27);
		return (-1);
	}
	return (0);
}

int			ft_check_arps(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0')
		return (1);
	return (0);
}
