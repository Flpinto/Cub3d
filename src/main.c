/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/06/08 18:21:56 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int argc, const char **argv)
{
    t_info *info;

    if (argc < 2 || argc > 3)
        return(0);

    info = ft_parse_info((char *)argv[1]);
   
    printf("Res X is %d\n", info->res_x);
    printf("Res Y is %d\n", info->res_y);
    printf("Color of floor is %d,%d,%d\n", info->color_f[0], info->color_f[1], info->color_f[2]);
    printf("Color of ceil is %d,%d,%d\n", info->color_c[0], info->color_c[1], info->color_c[2]);
    printf("South texture path : %s\n", info->texture_s);
    printf("North texture path : %s\n", info->texture_n);
    printf("Est   texture path : %s\n", info->texture_e);
    printf("West  texture path : %s\n", info->texture_w);
   // ft_destroy_info(info);
    return (0);
}