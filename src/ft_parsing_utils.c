/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 10:02:36 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/03 10:09:23 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int			ft_check_bmap(t_info info)
{
	int i;

	i = 0;
	while (info.buff[i])
	{
		if (info.buff[i] != ' ' && info.buff[i] != '\t' && info.buff[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

t_info		ft_free_tab_c(t_info info)
{
	ft_free_tab(&info);
	info.v = 0;
	return (info);
}
