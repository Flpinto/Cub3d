/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:37:28 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/16 18:17:51 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_len(unsigned int nbr)
{
	unsigned int len;

	len = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		++len;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				nbrlen;
	int				index;
	unsigned int	nb;

	if (n < 0)
		nb = (unsigned int)-n;
	else
		nb = (unsigned int)n;
	nbrlen = ft_num_len(nb);
	index = 0;
	if (!(res = (char *)malloc(sizeof(char) * nbrlen + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0 && (res[index] = '-'))
		nbrlen++;
	index = nbrlen - 1;
	while (nb >= 10)
	{
		res[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	res[index] = (char)(nb % 10 + 48);
	res[nbrlen] = '\0';
	return (res);
}
