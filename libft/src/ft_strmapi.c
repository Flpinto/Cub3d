/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:04:56 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/16 12:03:33 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstr;

	if (!s || !f)
		return (NULL);
	i = 0;
	nstr = ft_strdup(s);
	if (!nstr)
		return (NULL);
	while (nstr[i])
	{
		nstr[i] = (*f)(i, nstr[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
