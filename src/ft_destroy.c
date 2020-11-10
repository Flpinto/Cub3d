/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 18:18:57 by flpinto           #+#    #+#             */
/*   Updated: 2020/11/09 12:19:24 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	    *ft_strdel(char *s)
{
	if (s != NULL)
	{
		s = NULL;
		free(s);
		s = NULL;
	}
    return (s);
}

t_info      *ft_destroy_map(t_info *info)
{
    int i;

    i = 0;
    while (info->map[i])
    {
        info->map[i] = ft_strdel(info->map[i]);
        i++;
    }
    return (info);
}
/*
t_game    *ft_destroy_game(t_game *game)
{
    game->win = NULL;
    free(game->win);
    game->mlx = NULL;
    free(game->mlx);
    return (game);
}
*/
t_info      *ft_destroy_info(t_info *info)
{
    ft_strdel(info->texture_n);
    ft_strdel(info->texture_w);
    ft_strdel(info->texture_e);
    ft_strdel(info->texture_s);
    ft_strdel(info->texture_sprite);
    info = ft_destroy_map(info);
    return (info);
}
int         ft_destroy_all(t_all *all)
{
    all->info = ft_destroy_info(all->info);
    //all.game = ft_destroy_game(all.game);
    return (0);
}