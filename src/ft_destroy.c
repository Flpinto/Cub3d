/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:57 by flpinto           #+#    #+#             */
/*   Updated: 2020/10/15 12:36:34 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_strdel(char *s)
{
	if (s != NULL)
	{
		s = NULL;
		free(s);
		s = NULL;
	}
}

void    ft_destroy_game(t_game *game)
{
    game->win = NULL;
    free(game->win);
    game->mlx = NULL;
    free(game->mlx);
}

void    ft_destroy_info(t_info *info)
{
    int i;

    i = 0;
    ft_strdel(info->texture_e);
    ft_strdel(info->texture_w);
    ft_strdel(info->texture_s);
    ft_strdel(info->texture_n);
    ft_strdel(info->texture_sprite);
    while (i++ < 4)
        ft_strdel(info->color_c[i]);
    i = 0;
    while (i++ < 4)
        ft_strdel(info->color_f[i]);

}
int    ft_destroy_all(t_all *all)
{
    ft_destroy_info(&all->info);
    ft_destroy_game(&all->game);
    return (0);
}

