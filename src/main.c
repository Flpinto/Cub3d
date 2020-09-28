/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/09/24 10:42:17 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int argc, const char **argv)
{
    t_info *info;

    if (argc < 2 || argc > 3)
        return(0);

    info = ft_parse_info((char *)argv[1]);
    
    if (ft_check_map(info->map, info) == -1)
    {
        ft_destroy_info(info);
        return (0);
    }
    info = ft_run_game(info);
    ft_destroy_info(info);
    return (0);
}