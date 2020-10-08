/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:02:35 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/08 17:44:15 by flpinto          ###   ########.fr       */
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
int     ft_exit_window(t_all *all)
{   
    mlx_destroy_window(all->game->mlx, all->game->win);
    exit(0);
}

void    ft_move_in_map(int key, t_all *all)
{
    printf("hello %d %d\n", key, all->info->res_x);

}
int     ft_keypress(int key, t_all *all)
{
    if (key == 119 || key == 97 || key == 115 || key == 100)
        ft_move_in_map(key, all);
    if (key ==  652930)
    {
        mlx_clear_window(all->game->mlx, all->game->win);
        mlx_do_sync(all->game->mlx);
    }
    printf("%d\n", key);
    if (key == ESC)
        ft_exit_window(all);
    printf("PRESS\n");

    return(0);
}
t_draw_map    *ft_init_draw(t_draw_map *draw, t_all *all)
{
    draw->max_x = ft_strlen(all->info->map[1]);
    draw->max_y = ft_len_map(all->info->map);
    draw->mini_x = all->info->res_x / draw->max_x;
    draw->mini_y = all->info->res_y / draw->max_y;
    draw->wall_color = 0xff0000;
    draw->floor_color = 0x808080;
    return (draw);

}
void    ft_draw_map(t_all *all)
{
    t_draw_map *draw;
    int x;
    int y;

    x = 0;
    y = 1;
    draw = ft_calloc(sizeof(t_draw_map), 1);
    draw = ft_init_draw(draw, all);
    draw->y = 0;
    printf("Mini_y = %d\n", draw->mini_y);
    while (y * draw->mini_y < y * draw->mini_y + draw->mini_y && y * draw->mini_y < all->info->res_y)
    {
        x = 0;
        while (x * draw->mini_x < x * draw->mini_x + draw->mini_x && x * draw->mini_x < all->info->res_x)
        {   
            if (all->info->map[y][x] == '1')
                mlx_pixel_put(all->game->mlx, all->game->win, x, y, draw->wall_color);
            else
                mlx_pixel_put(all->game->mlx, all->game->win, x, y, draw->floor_color);
            x++;
        }
        y++;
    }
    mlx_do_sync(all->game->mlx);
}

t_all  *ft_run_game(t_all *all)
{
    

    all->game = ft_calloc(sizeof(t_all), 1);
    all->game->mlx = mlx_init();
    all->game->win = mlx_new_window(all->game->mlx, all->info->res_x, all->info->res_y, "Cub3d by Mollo");
    ft_draw_map(all);
    mlx_hook(all->game->win, 2, 1L<<0, (*ft_keypress), &all);
    mlx_loop(all->game->mlx);
    return (all);
}