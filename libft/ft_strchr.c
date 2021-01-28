/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:59:46 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/24 14:34:50 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *r;

	if (!s)
		return (NULL);
	r = (char *)s;
	while (*r != c)
	{
		if (!*r)
			return (0);
		r++;
	}
	return (r);
}
