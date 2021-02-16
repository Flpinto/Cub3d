/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:08:39 by flpinto           #+#    #+#             */
/*   Updated: 2021/02/01 15:11:59 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include "../libft/libft.h"

# define MAX 1024
# define BUFFER_SIZE 1024

int			get_next_line(int fd, char **line);
size_t	    ft_strlenz(const char *str);
char		*ft_strcpy(char *dest, char *src);
char		*ft_join(char *s1, char *s2, size_t len);

#endif
