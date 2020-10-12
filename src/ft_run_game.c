/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:02:35 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/12 13:29:20 by flpinto          ###   ########.fr       */
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
t_draw_map    *ft_init_draw(t_draw_map *draw, t_all all)
{
    draw->max_x = ft_strlen(all.info.map[1]);
    draw->max_y = ft_len_map(all.info.map);
    draw->mini_x = all.info.res_x / draw->max_x;
    draw->mini_y = all.info.res_y / draw->max_y;
    draw->wall_color = 0xff0000;
    draw->floor_color = 0x808080;
    draw->player_color = 0x00ff00;

    return (draw);

}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    ft_draw_mini_map(t_all *all)
{
    t_draw_map  draw;
    int x;
    int y;

    x = 0;
    y = 1;
    draw = ft_calloc(sizeof(t_draw_map), 1);
    draw = ft_init_draw(&draw, all);
    draw.y = 0;
    while (y * draw.mini_y < y * draw.mini_y + draw.mini_y && y * draw.mini_y < all.info.res_y)
    {
        draw.mini_y_s = draw.mini_y;
        while(draw.mini_y_s != 0)
        {
            x = 0;
            draw.x = 0;
            while (x * draw.mini_x < x * draw.mini_x + draw.mini_x && x * draw.mini_x < all.info.res_x)
            {
                draw.mini_x_s = draw.mini_x;
                while (draw.mini_x_s != 0)
                {
                    if (all.info.map[y][x] == '1')
                        my_mlx_pixel_put(&all.img, draw.x, draw.y, draw.wall_color);
                    else
                        my_mlx_pixel_put(&all.img, draw.x, draw.y, draw.floor_color);
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
    
}

int     ft_exit_window(t_all *all)
{   
    mlx_destroy_window(all->game.mlx, all->game.win);
    ft_destroy_all(&all);
    exit(0);
}

int    ft_move_in_map(int key, t_all *all)
{
    if (key == TOP)
    {
        printf("Pos -- %d %d --\n", all.info.pos_y, all.info.pos_x);
    }
    return (0);
}
int    ft_keypress(int key, t_all *all)
{
    printf("kepose -- %d %d --\n", all.info.pos_y, all.info.pos_x);
    if (key == TOP || key == BOT || key == LEFT || key == RIGHT)
        ft_move_in_map(key, all);
    if (key ==  ESC)
        ft_exit_window(&all);
    return (0);
}

int     ft_keyrelease(int key)
{
    printf("Release - %d - \n", key);
    return (0);
}



t_all  *ft_run_game(t_all *all)
{
    all->game.mlx = mlx_init();
    all->game.win = mlx_new_window(all->game.mlx, all.info.res_x, all.info.res_y, "Cub3d by Mollo");
    all->img.img = mlx_new_image(all.game.mlx, all.info.res_x, all.info.res_y);
    all->img.addr = mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel, &all.img.line_length,
                                 &all.img.endian);
    
                     
    ft_draw_mini_map(all);
    mlx_put_image_to_window(all.game.mlx, all.game.win, all.img.img, 0, 0);
    printf("Pos -- %d %d --\n", all.info.pos_y, all.info.pos_x);
    mlx_hook(all.game.win, 2, 1L<<0, (*ft_keypress), &all);
    mlx_hook(all.game.win, 3, 1L<<1, (*ft_keyrelease), &all);
    mlx_loop(all.game.mlx);
    return (all);
}