/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:14:09 by flpinto           #+#    #+#             */
/*   Updated: 2020/05/30 15:27:22 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int				del_stat(char **statst)
{
	if (statst != NULL)
	{
		free(*statst);
		*statst = NULL;
	}
	return (0);
}

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char*)b;
	while (len > 0)
	{
		*(ptr++) = (unsigned char)c;
		len--;
	}
	return (b);
}

char			*ft_strjoin(char *s1, char *s2, size_t len)
{
	char			*str;
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + len + 1))))
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

static char		*save_endl(char *endl)
{
	if (ft_strchr(endl, '\n'))
	{
		ft_strcpy(endl, ft_strchr(endl, '\n') + 1);
		return (endl);
	}
	else if (ft_strlen(endl) > 0)
	{
		ft_strcpy(endl, ft_strchr(endl, '\0'));
		return (endl);
	}
	return (NULL);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*statst[MAX];
	int				ret;
	char			*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(statst[fd]) && !(statst[fd] = ft_calloc(1, sizeof(int))))
		return (-1);
	while (!(ft_strchr(statst[fd], '\n')) &&
				(ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = statst[fd];
		statst[fd] = ft_strjoin(tmp, buf, ret);
		free(tmp);
	}
	tmp = ft_substr(statst[fd], 0, ft_strlen(statst[fd]));
	*line = tmp;
	tmp = NULL;
	free(tmp);
	tmp = NULL;
	if (ft_strchr(statst[fd], '\n') == NULL)
		return (del_stat(&statst[fd]));
	return ((save_endl(statst[fd]) == NULL) ? 0 : 1);
}
