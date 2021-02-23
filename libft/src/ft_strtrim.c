/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:21:39 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/16 12:03:46 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		is_set(char const *set, char c)
{
	unsigned int a;

	a = 0;
	while (set[a])
	{
		if (set[a] == c)
			return (1);
		a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (is_set(set, s1[i]) == 1 && s1[i])
		i++;
	start = i;
	i = ft_strlen(s1);
	if (i-- != start)
		while (is_set(set, s1[i]) == 1)
			i--;
	end = i + 1;
	if (!(new = malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (end > start)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}
