/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:02:35 by flpinto           #+#    #+#             */
/*   Updated: 2020/09/22 02:11:33 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_info  *ft_run_game(t_info *info)
{
    t_game  *game;
    int x = 426;
    int y = 240;

    game = ft_calloc(sizeof(t_game), 1);
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, 1280, 720, "Cub3d");
    while (y++ < 480)
    {
        x = 426;
        while (x++ < 853)
        {
            mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, 0xbfefff);
        }
    }
    mlx_loop(game->mlx_ptr);
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    
    return (info);
}