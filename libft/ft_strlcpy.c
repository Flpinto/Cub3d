/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:01:31 by flpinto           #+#    #+#             */
/*   Updated: 2020/11/30 16:17:07 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i])
		i++;
	if (dstsize > 0)
	{
		while (a < dstsize - 1 && src[a])
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (i);
}
