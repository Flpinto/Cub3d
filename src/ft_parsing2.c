/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:36:46 by flpinto           #+#    #+#             */
/*   Updated: 2020/06/08 18:21:27 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    ft_get_textures(char *mapline, t_info *texture)
{
    if (*mapline == 'S')
        texture->texture_s = ft_strdup(mapline += 2);
    if (*mapline == 'N')
        texture->texture_n = ft_strdup(mapline += 3);
    if (*mapline == 'W')
        texture->texture_w = ft_strdup(mapline += 3);
    if (*mapline == 'E')
        texture->texture_e = ft_strdup(mapline += 3);
}
