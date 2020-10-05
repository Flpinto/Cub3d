/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:14:11 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/15 17:03:43 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int a;
	unsigned int b;

	b = 0;
	a = 0;
	i = 0;
	while (src[a])
		a++;
	while (dest[i] && i < dstsize)
		i++;
	if (i < dstsize)
	{
		while (src[b] && b + i < dstsize - 1)
		{
			dest[i + b] = src[b];
			b++;
		}
		if (dest[i + b] != '\0')
			dest[i + b] = '\0';
		return (i + a);
	}
	return (a + dstsize);
}
