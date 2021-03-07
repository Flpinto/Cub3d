/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:17:06 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/07 12:09:11 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_sort_sprite_plus(t_all *all, int a, double tmp)
{
	tmp = all->sprite->x[a];
	all->sprite->x[a] = all->sprite->x[a + 1];
	all->sprite->x[a + 1] = tmp;
	tmp = all->sprite->y[a];
	all->sprite->y[a] = all->sprite->y[a + 1];
	all->sprite->y[a + 1] = tmp;
	tmp = all->sprite->distancex[a];
	all->sprite->distancex[a] = all->sprite->distancex[a + 1];
	all->sprite->distancex[a + 1] = tmp;
	tmp = all->sprite->distancey[a];
	all->sprite->distancey[a] = all->sprite->distancey[a + 1];
	all->sprite->distancey[a + 1] = tmp;
	tmp = all->sprite->mat[a];
	all->sprite->mat[a] = all->sprite->mat[a + 1];
	all->sprite->mat[a + 1] = tmp;
	tmp = all->sprite->tformx[a];
	all->sprite->tformx[a] = all->sprite->tformx[a + 1];
	all->sprite->tformx[a + 1] = tmp;
	tmp = all->sprite->tformy[a];
	all->sprite->tformy[a] = all->sprite->tformy[a + 1];
	all->sprite->tformy[a + 1] = tmp;
}

void	ft_sort_sprite(t_all *all)
{
	int		a;
	int		b;
	double	tmp;

	b = 0;
	while (b < all->sprite->count)
	{
		a = 0;
		while (a < all->sprite->count)
		{
			if (all->sprite->distance[a] > all->sprite->distance[a + 1])
			{
				tmp = all->sprite->order[a];
				all->sprite->order[a] = all->sprite->order[a + 1];
				all->sprite->order[a + 1] = tmp;
				tmp = all->sprite->distance[a];
				all->sprite->distance[a] = all->sprite->distance[a + 1];
				all->sprite->distance[a + 1] = tmp;
				ft_sort_sprite_plus(all, a, tmp);
			}
			a++;
		}
		b++;
	}
}
