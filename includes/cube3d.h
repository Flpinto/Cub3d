/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:21:45 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/10 15:01:58 by flpinto          ###   ########.fr       */
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
# define RRIGHT 65361
# define RLEFT 65363

typedef struct      s_vect
{
    int     y;
    int     x;
}                   t_vect;

typedef struct      s_ray
{
    double  time;
    double  oldtime;
    double  camx;
    double  raydirx;
    double  raydiry;
    int     lmapx;
    double  sidedistx;
    double  sidedisty;
    double  deltadistx;
    double  deltadisty;
    double  perpwalldist;
    double  step;
    double  stepx;
    double  stepy;
    int     hit;
    int     side;
    double  lineh;
    int     drawst;
    int     drawend;
    int     textnum;
    double  wallx;
    int     texx;
    int     texy;
    double  texpos;
    int     vectx;
    int     vecty;
    int     x;
    int     y;  
}                   t_ray;

typedef struct      s_game
{
    void    *mlx;
    void    *win;
    
}                   t_game;

typedef struct  s_data {
    void    *img[6];
    char    *addr[6];
    int     bits_per_pixel[6];
    int     line_length[6];
    int     endian[6];
    int		textw[6];
	int		texth[6];
	float	x;
	float	xb;
	float	y;
	float	yb;
	float	tilex;
	float	tiley;
	int		crgb;
	int		ok;
	int		frgb;
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
    double     pos_x;
    double     pos_y;
    char    orient;
    char    *buff;
    int     i;
    int     end;
    int     mapsize;
    int     maplen; 
    char    **tab;
    int     startmap;
    double  mapx;
    double  mapy;
    double  dirx;
    double  diry;
    double  planex;
    double  planey;
    int     key;
}                   t_info;

typedef struct      s_all
{
    t_info  *info;
    t_game  *game;
    t_data  *img;
    t_ray   *ray;
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
t_data      ft_get_img_by_file(t_data img, t_all all);
int         ft_check_first_line(char *line);
int         ft_mv_n(int key, t_all *all);
int         ft_init_ray(t_ray *ray);
int         ft_ray(t_all *all);
void        ft_loop(t_all *all);
void	    ft_move_cam(t_all *all);
int         ft_exit_window(t_all *all);
void        ft_init_direction(t_all *all);
int         ft_keypressed(t_all *all);
int         ft_keypress(int key, t_all *all);
int         ft_keyrelease(int key, t_all *all);
int         ft_move_in_map(int key, t_all *all);

# endif