/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:26:29 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/10 15:30:03 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = (0);
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	if (last)
		return (last);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
