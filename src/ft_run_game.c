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

int     ft_len_map(char **map)
{
    int y;

    y = 0; 
    while (map[y])
        y++;
    return (y - 1);
}
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
    if (key == 119 || key == 97 || key == 115 || key == 100)
        ft_move_in_map(key)
    if (key ==  652930)
    {
        mlx_clear_window(game->mlx, game->win);
        mlx_do_sync(game->mlx);
    }
    printf("%d\n", key);
    if (key == 65307)
        ft_exit_window(game);
    printf("PRESS\n");

    return(0);
}

t_draw_map    *ft_draw_map(t_info *info, t_game *game)
{
    t_draw_map *draw;

    draw = ft_calloc(sizeof(t_draw_map), 1);
    draw->max_x = ft_strlen(info->map[1]);
    draw->max_y = ft_len_map(info->map);
    printf("%d\n", draw->max_y);
    draw->mini_x = info->res_x / draw->max_x;
    draw->mini_y = info->res_y / draw->max_y;
    draw->mini_y_s = draw->mini_y;
    draw->mini_x_s = draw->mini_x;
    draw->y = 0;
printf("----%d----\n", draw->mini_x);
    while (draw->y < info->res_y)
    {
        draw->x = 0;
        while (draw->x < info->res_x)
        {
            if (draw->mini_y == 0)
            {
                mlx_pixel_put(game->mlx, game->win, draw->x, draw->y, 0xff0000);
            }
            if (draw->mini_x == 0)
            {
                mlx_pixel_put(game->mlx, game->win, draw->x, draw->y, 0xff0000);
            }
            draw->x++;
            if (draw->mini_x == 0)
                draw->mini_x = draw->mini_x_s;
            else
                draw->mini_x--;
        }
        if (draw->mini_y == 0)
            draw->mini_y = draw->mini_y_s;
        else
            draw->mini_y--;
        draw->y++;
    }
    mlx_do_sync(game->mlx);
    return (0);
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