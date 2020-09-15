/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:02:35 by flpinto           #+#    #+#             */
/*   Updated: 2020/09/15 15:56:01 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_game  *ft_set_params_game(t_info *info)
{
    t_game *game;

    game = ft_calloc(sizeof(t_game), 1);
    game->pos_x = info->pos_x;
    game->pos_y = info->pos_y;
    game->res_width = info->res_x;
    game->res_height = info->res_y;
    return (game);
}

t_info  *ft_run_game(t_info *info)
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_game  *game;

    
    mlx_ptr = mlx_init();
    game = ft_set_params_game(info);
    win_ptr = mlx_new_window(mlx_ptr, 1080, 1920, "Game");
    mlx_pixel_put(mlx_ptr, win_ptr, 540, 960, 0);
    return (info);
}