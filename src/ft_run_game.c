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
int     ft_exit_window(t_all *all)
{   
    mlx_destroy_window(all->game->mlx, all->game->win);
    exit(0);
}

int     ft_keyrelease()
{
    printf("RELEASE\n");

    return(0);
}

void    ft_move_in_map(int key)
{
    printf("hello %d \n", key);
}
int     ft_keypress(int key, t_all *all)
{
    if (key == 119 || key == 97 || key == 115 || key == 100)
        ft_move_in_map(key);
    if (key ==  652930)
    {
        mlx_clear_window(all->game->mlx, all->game->win);
        mlx_do_sync(all->game->mlx);
    }
    printf("%d\n", key);
    if (key == 65307)
        ft_exit_window(all);
    printf("PRESS\n");

    return(0);
}

t_draw_map    *ft_draw_map(t_all *all)
{
    t_draw_map *draw;

    draw = ft_calloc(sizeof(t_draw_map), 1);
    draw->max_x = ft_strlen(all->info->map[1]);
    draw->max_y = ft_len_map(all->info->map);
    printf("%d\n", draw->max_y);
    draw->mini_x = all->info->res_x / draw->max_x;
    draw->mini_y = all->info->res_y / draw->max_y;
    draw->mini_y_s = draw->mini_y;
    draw->mini_x_s = draw->mini_x;
    draw->y = 0;
printf("----%d----\n", draw->mini_x);
    while (draw->y < all->info->res_y)
    {
        draw->x = 0;
        while (draw->x < all->info->res_x)
        {
            if (draw->mini_y == 0)
            {
                mlx_pixel_put(all->game->mlx, all->game->win, draw->x, draw->y, 0xff0000);
            }
            if (draw->mini_x == 0)
            {
                mlx_pixel_put(all->game->mlx, all->game->win, draw->x, draw->y, 0xff0000);
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
    mlx_do_sync(all->game->mlx);
    return (0);
}

t_all  *ft_run_game(t_all *all)
{
    

    all->game = ft_calloc(sizeof(t_all), 1);
    all->game->mlx = mlx_init();
    all->game->win = mlx_new_window(all->game->mlx, all->info->res_x, all->info->res_y, "Cub3d by Mollo");
    ft_draw_map(all);
    mlx_hook(all->game->win, 2, 1L<<0, (*ft_keypress), &all);
    mlx_hook(all->game->win, 3, 1L<<1, (*ft_keyrelease), &all);
    mlx_loop(all->game->mlx);
    
    return (all);
}