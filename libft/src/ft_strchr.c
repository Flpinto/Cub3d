/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:59:46 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/16 12:03:08 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
