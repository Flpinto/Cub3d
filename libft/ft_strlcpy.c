/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:01:31 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/21 16:20:16 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	a;
	unsigned int	lenght;

	if (!dest || !src)
		return (0);
	lenght = ft_strlen(src);
	if (dstsize > 0)
	{
		a = 0;
		while (src[a] != '\0' && a < dstsize - 1)
		{
			dest[a] = src[a];
			a++;
		}
		dest[a] = '\0';
	}
	return (lenght);
}
