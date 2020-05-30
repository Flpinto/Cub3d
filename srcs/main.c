/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/05/30 15:46:29 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <stdio.h>

int     main(int ar, char *av[])
{
    char **line;

    line = NULL;

    printf("%s", get_next_line(*av[1], line));
    return (0);
}