/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:05:44 by flpinto           #+#    #+#             */
/*   Updated: 2019/10/29 10:19:20 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		in_charset(char c, char *charset)
{
	if (charset[0] == c)
		return (1);
	return (0);
}

int		ft_count_word(char const *s, char *charset)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (in_charset(s[i], charset))
		{
			words++;
			while (in_charset(s[i], charset) && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

char	*ft_len_word(char const *s, char *charset)
{
	int		len;
	int		k;
	char	*word;

	len = 0;
	while (s[len] && !in_charset(s[len], charset))
		len++;
	if (!(word = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	k = 0;
	while (len > k)
	{
		word[k] = s[k];
		k++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;
	char	charset[1];

	charset[0] = c;
	if (!s || !(tab = malloc(sizeof(char *) * (ft_count_word(s, charset) + 2))))
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		if (in_charset(s[i], charset))
			while (s[i] && in_charset(s[i], charset))
				i++;
		else
		{
			tab[k++] = ft_len_word(s + i, charset);
			while (s[i] && !in_charset(s[i], charset))
				i++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
