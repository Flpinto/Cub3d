/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:14:34 by flpinto           #+#    #+#             */
/*   Updated: 2021/01/23 12:51:29 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t		ft_strlenz(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] && str[count] != '\n')
	{
		count++;
	}
	return (count);
}

char		*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char		*ft_join(char *s1, char *s2, size_t len)
{
	char			*str;
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	if (!(str = malloc(sizeof(char) * (ft_strlenz(s1) + len + 1))))
		return (NULL);
	tmp = str;
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] && len > 0)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str - (str - tmp));
}
