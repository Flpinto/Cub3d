/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:28:16 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/10 11:45:57 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int    ft_keypress(int key, t_all *all)
{
    all->info->key = key;
    return (0);
}

int     ft_keyrelease(int key, t_all *all)
{
    printf("Release - %d - \n", key);
    all->info->key = 0;
    return (0);
}

int     ft_keypressed(t_all *all)

{
    if (all->info->key == TOP || all->info->key == BOT || 
                all->info->key == LEFT || all->info->key == RIGHT)
        ft_move_in_map(all->info->key, all);
    if (all->info->key == RLEFT || all->info->key == RRIGHT)
        ft_move_cam(all);
    if (all->info->key ==  ESC)
        ft_exit_window(all);
    ft_loop(all);
    return (0);
}