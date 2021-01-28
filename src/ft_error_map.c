/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:15:24 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/26 23:10:16 by flpinto          ###   ########.fr       */
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
	c == ' ' || c == '0' ||c == '1' || c == '2')
		return (1);
	return (0);
}

void		ft_error_wall_border(void)
{
	printf("Error : hole on border's wall\n");
}
