/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:15:24 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/23 11:48:06 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_check_stpos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int		ft_check_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' ||
	c == ' ' || c == '0' || c == '1' || c == '2')
		return (1);
	if (c == ' ')
		c = 1;
	return (0);
}

int		ft_error_char(void)
{
	write(1, "Error : Wrong map character\n", 28);
	return (-1);
}

int		ft_error_wall_border(void)
{
	write(1, "Error : hole on border's wall\n", 30);
	return (-1);
}

int		ft_error_hole(void)
{
	write(1, "Error : Dangerous void in map\n", 30);
	return (-1);
}
