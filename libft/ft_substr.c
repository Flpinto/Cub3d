/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:22:38 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/29 10:13:56 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	if (i < start)
		len = 0;
	if (!(nstr = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[start] && s[i])
	{
		nstr[i] = s[start];
		start++;
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
