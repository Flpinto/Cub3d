/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:47:07 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/16 12:03:41 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int a;
	unsigned int b;

	if (!*needle)
		return ((char*)haystack);
	a = 0;
	while (haystack[a] && a < len)
	{
		if (haystack[a] == needle[0])
		{
			b = 1;
			while (needle[b] && haystack[a + b] == needle[b] &&
				(a + b) < len)
				b++;
			if (needle[b] == '\0')
				return ((char *)&haystack[a]);
		}
		a++;
	}
	return (NULL);
}
