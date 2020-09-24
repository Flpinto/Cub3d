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

int     ft_mouse_enter_window()
{
    printf("HEllo\n");

    return(0);
}

int     ft_mouse_exit_window()
{
    printf("BYe\n");

    return(0);
}

int     ft_render(t_game *game)
{
    return(0);
}
/*
int     ft_clear_window(int keycode, t_game *game)
{
    
    printf("KY-%d\n", keycode);
    if (keycode == 65307)
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    mlx_do_key_autorepeatoff(game->mlx_ptr);
    return (0);
}
*/
t_info  *ft_run_game(t_info *info)
{
    t_game  *game;
/*   
    int x = 426;
    int y = 240;
*/
    game = ft_calloc(sizeof(t_game), 1);
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, 1280, 720, "Cub3d");

 /*   while (y++ < 480)
    {
        x = 426;
        while (x++ < 853)
        {
            mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, 0xbfefff);
        }
    }


    mlx_hook(game->win_ptr, 7, 1L<<4, ft_mouse_enter_window, &game->mlx_ptr);
    mlx_hook(game->win_ptr, 7, 1L<<5, ft_mouse_exit_window, &game->mlx_ptr);
    mlx_hook(game->win_ptr, 2, 1L<<0, ft_clear_window, &game->mlx_ptr);
    */
    mlx_loop_hook(game->mlx_ptr, ft_clear_window, &game);
    mlx_loop(game->mlx_ptr);
    
    return (info);
}