/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/24 16:37:07 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int argc, const char **argv)
{
    t_info  info;
    t_all   all;


    if (argc == 1)
    {   
        write(1, "no map\n", 7);
		exit(0);
    }
    info = ft_parse_info((char *)argv[1], info);
    all.info = &info;
    
    printf("Res : %d x %d\n", all.info->res_x, all.info->res_y);
    printf("Color Floor : %d,%d,%d\n", info.color_f[0], info.color_f[1], info.color_f[2]);
    printf("Color Wall : %d,%d,%d\n", info.color_c[0], info.color_c[1], info.color_c[2]);
    printf("Path S - %s\nPath N - %s\nPath E - %s\nPath W - %s\nPath Sp - %s\n", info.texture_s, info.texture_n, info.texture_w, info.texture_e, info.texture_sprite);
    /*
    if (ft_check_map(all.info.map, &all.info) == -1)
    {
        printf("ERRRORORORORRORORO");
        //ft_destroy_all(&all);
        //return (0);
    }
    */
   
   // ft_run_game(&all);
   // ft_destroy_all(&all);
    return (0);
}