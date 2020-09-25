/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:02:35 by flpinto           #+#    #+#             */
/*   Updated: 2020/09/24 11:28:12 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


int     ft_exit_window(t_game *game)
{   
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
}

int     ft_keyrelease()
{
    printf("RELEASE\n");

    return(0);
}

int     ft_keypress(int key, t_game *game)
{
    if (key == 65307)
        ft_exit_window(game);
    printf("PRESS\n");

    return(0);
}

int     ft_draw_map(t_info *info, t_game *game)
{

}

t_info  *ft_run_game(t_info *info)
{
    t_game  *game;

    game = ft_calloc(sizeof(t_game), 1);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, info->res_x, info->res_y, "Cub3d by Mollo");
    ft_draw_map(info, game);
    mlx_hook(game->win, 2, 1L<<0, (*ft_keypress), &game->mlx);
    mlx_hook(game->win, 3, 1L<<1, (*ft_keyrelease), &game->mlx);
    mlx_loop(game->mlx);
    
    return (info);
}