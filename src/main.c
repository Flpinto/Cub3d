/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/16 13:25:47 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int argc, const char **argv)
{
    t_info  info;
    t_all   all;


    if (argc < 2 || argc > 3)
        return(0);
    ft_parse_info((char *)argv[1], &info);
    all.info = &info;
    
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