/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/07 21:38:38 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_all   *ft_init_all(t_all *all)
{
    all->game = ft_calloc(sizeof(t_game), 1);
    all->info = ft_calloc(sizeof(t_info), 1);
    return(all);
}
int     main(int argc, const char **argv)
{
    t_all   *all;

    if (argc < 2 || argc > 3)
        return(0);
    all = ft_calloc(sizeof(t_all), 1);
    all = ft_init_all(all);
    all->info = ft_parse_info((char *)argv[1]);
    
    if (ft_check_map(all->info->map, all->info) == -1)
    {
        ft_destroy_all(all);
        return (0);
    }
    all = ft_run_game(all);
    ft_destroy_all(all);
    return (0);
}