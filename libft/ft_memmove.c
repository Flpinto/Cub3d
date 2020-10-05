/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:18:13 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/17 16:39:02 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*psrc;
	char		*pdst;

	psrc = src;
	pdst = dst;
	if (!len && !dst)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	psrc += len;
	pdst += len;
	while (len--)
		*--pdst = *--psrc;
	return (dst);
}
