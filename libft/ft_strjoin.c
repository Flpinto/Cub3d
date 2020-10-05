/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 12:46:21 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/28 17:06:30 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	a;
	unsigned int	b;
	char			*nstr;

	a = 0;
	b = -1;
	if (!s1 || !s2)
		return (NULL);
	if (!(nstr = malloc(sizeof(char const) *
			(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[++b])
	{
		nstr[a] = s1[b];
		a++;
	}
	b = -1;
	while (s2[++b])
	{
		nstr[a] = s2[b];
		a++;
	}
	nstr[a] = '\0';
	return (nstr);
}
