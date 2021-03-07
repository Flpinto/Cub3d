/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:45:08 by flpinto           #+#    #+#             */
/*   Updated: 2021/03/06 19:36:17 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(void *a, void *b)
{
	void	*c;

	c = a;
	a = b;
	b = c;
}