/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:21:39 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/16 12:02:23 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;
	size_t				i;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
			return ((void*)(pdst + i + 1));
		i++;
	}
	return (NULL);
}
