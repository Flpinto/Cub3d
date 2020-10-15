/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/15 12:45:15 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int     main(int argc, const char **argv)
{
    t_all   all;

    if (argc < 2 || argc > 3)
        return(0);
    ft_parse_info((char *)argv[1], &all.info);
    if (ft_check_map(all.info.map, &all.info) == -1)
    {
        ft_destroy_all(&all);
        return (0);
    }
    ft_run_game(&all);
    ft_destroy_all(&all);
    return (0);
}