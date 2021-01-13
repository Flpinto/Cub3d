/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:02:35 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/10 12:14:52 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_draw_map    *ft_init_draw(t_draw_map *draw, t_all all)
{

    draw->max_x = all.info->mapsize;
    draw->max_y = all.info->maplen;
    draw->mini_x = all.info->res_x / draw->max_x;
    draw->mini_y = all.info->res_y / draw->max_y;
    draw->wall_color = 0xff0000;
    draw->floor_color = 0x808080;
    draw->player_color = 0x00ff00;

    return (draw);

}

void    ft_print_map(char **map, t_all *all)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '0' && map[y][x] == map[(int)all->info->pos_y][(int)all->info->pos_x])
                printf("X");
            else
                printf("%c", map[y][x]);
            x++;
        }
        printf("\n"); 
        y++;
    }
}


t_all  ft_run_game(t_all all)
{
    t_game      game;
    t_data      img;
    t_ray       ray;

    all.ray = &ray;
    all.game = &game;
    all.game->mlx = mlx_init();
    all.game->win = mlx_new_window(all.game->mlx, all.info->res_x, all.info->res_y, "Cub3d by Mollo");
    img.img[0] = mlx_new_image(all.game->mlx, all.info->res_x, all.info->res_y);
    img = ft_get_img_by_file(img, all);
    all.img = &img;
    //ft_draw_mini_map(all);
    
    all.info->pos_x = 0;
    all.info->pos_y = 0;
    ft_init_direction(&all);
    ft_ray(&all);
    
    mlx_put_image_to_window(all.game->mlx, all.game->win, all.img->img[0], 0, 0);
    mlx_hook(all.game->win, 2, 1L<<0, (*ft_keypress), &all);
    mlx_hook(all.game->win, 3, 1L<<1, (*ft_keyrelease), &all);
    mlx_loop_hook(all.game->mlx, (*ft_keypressed), &all);
    mlx_loop(all.game->mlx);
    return (all);
}

/*

    x = 0;
    y = 0;
    ft_init_draw(&draw, all);
    draw.y = 0;
    while (y * draw.mini_y < y * draw.mini_y + draw.mini_y && y * draw.mini_y < all.info->res_y)
    {
        draw.mini_y_s = draw.mini_y;
        while(draw.mini_y_s != 0)
        {
            x = 0;
            draw.x = 0;
            while (x * draw.mini_x < x * draw.mini_x + draw.mini_x && x * draw.mini_x < all.info->res_x)
            {
                draw.mini_x_s = draw.mini_x;
                while (draw.mini_x_s != 0 && all.info->map[y][x])
                {
                    
                    if (all.info->map[y][x] == '1')
                        my_mlx_pixel_put(all.img, draw.x, draw.y, draw.wall_color);
                    else
                        my_mlx_pixel_put(all.img, draw.x, draw.y, draw.floor_color);
                    draw.x++;
                    draw.mini_x_s--;
                }
                x++;
            }
            draw.y++;
            draw.mini_y_s--;
        }
        y++; 
    }

*/