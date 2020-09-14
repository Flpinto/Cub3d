/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:21:45 by flpinto           #+#    #+#             */
/*   Updated: 2020/09/07 17:55:26 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"


typedef struct       s_info
{   
    void    *tmp_mlx;
    char    *texture_n;
    char    *texture_w;
    char    *texture_e;
    char    *texture_s;
    char    *texture_sprite;
    int     res_x;
    int     res_y;
    char     *color_f[3];
    char     *color_c[3];
    char    **map;
}                   t_info;

t_info      *ft_run_game(t_info *info);
t_info      *ft_parse_info(char *filemap);
void		ft_print_map(t_info *map);
void        ft_get_textures(char *mapline, t_info *texture);
int         ft_get_map(char *mapline, t_info *map);
void        ft_destroy_info(t_info *info);
int         ft_check_map(char **map);
int         ft_check_first_line(char *line);
void        ft_get_color_c(char *mapline, t_info *color);
void	    ft_get_color_f(char *mapline, t_info *color);

# endif