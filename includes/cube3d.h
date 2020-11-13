/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:21:45 by flpinto           #+#    #+#             */
/*   Updated: 2020/11/13 11:50:21 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
# define ESC 65307
# define TOP 119
# define BOT 115
# define LEFT 97
# define RIGHT 100

typedef struct      s_game
{
    void    *mlx;
    void    *win;
    
}                   t_game;

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}                   t_data;

typedef struct      s_draw_map
{
    int     x;
    int     y;
    int     max_x;
    int     max_y;
    int     mini_x;
    int     mini_y;
    int     mini_y_s;
    int     mini_x_s;
    int     wall_color;
    int     floor_color;
    int     player_color;
}                   t_draw_map;

typedef struct      s_info
{
    int		vno;
	int		vso;
	int		vwe;
	int		vea;
	int		vs;
	int		vf;
	int		vc;
	int		vr;
    int     vsp;
    int     v;
    int     vall;
    void    *tmp_mlx;
    char    *texture_n;
    char    *texture_w;
    char    *texture_e;
    char    *texture_s;
    char    *texture_sprite;
    int     res_x;
    int     res_y;
    int     color_f[3];
    int     color_c[3];
    char    **map;
    int     pos_x;
    int     pos_y;
    char    orient;
    char    *buff;
    int     i;
    int     end;
    int     mapsize;
    int     maplen; 
    char    **tab;
    int     startmap; 
}                   t_info;

typedef struct      s_all
{
    t_info  *info;
    t_game  *game;
    t_data  *img;
}                   t_all;

t_all       ft_run_game(t_all all);
t_info      ft_parse_info(char *filemap, t_info info);
t_info      ft_get_res(t_info info);
t_info      ft_get_color(t_info info, char c);
t_info	    ft_parse_s(t_info info);
t_info	    ft_parse_n(t_info info);
t_info  	ft_parse_w(t_info info);
t_info  	ft_parse_e(t_info info);
t_info	    ft_parse_sprite(t_info info);
t_info      ft_parse_map(t_info info, int fd, char *filemap);
t_info      ft_get_map(t_info info, int fd);
int         ft_destroy_all(t_all *all);
t_info      ft_check_map(t_info info);
int         ft_check_first_line(char *line);
int         ft_mv_n(int key, t_all *all);

# endif