/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:00:51 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/16 12:02:43 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char*)b;
	i = 0;
	while (len > i)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}
