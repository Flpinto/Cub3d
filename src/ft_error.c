/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:55:28 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/03 10:47:32 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_error_gnl(t_info *info)
{
	free(info->buff);
	ft_putstr_fd("Error : This is not a file\n", 1);
	exit(0);
}
