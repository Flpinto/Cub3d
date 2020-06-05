/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 15:31:07 by flpinto           #+#    #+#             */
/*   Updated: 2020/06/05 11:40:43 by flpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int     main(int argc, char **argv)
{
    char    *lineadress[1024];
    int     fd;
    int     i;
    int     j;

    j = 1;
    if (argc < 2 || argc > 3)
        return(0);

    if (!(fd = open(argv[1], O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}

    while ((i = get_next_line(fd, &lineadress[j - 1])) > 0)
    {
        if (ft_strnstr(lineadress[j - 1], "R ", strlen(lineadress[j - 1]))) 
            printf("okyy");
        if (ft_strnstr(lineadress[j - 1], "SO", strlen(lineadress[j - 1]))) 
            printf("okyy");
        printf("%s\n", lineadress[j - 1]); 
        j++;
    }
    printf("%s\n", lineadress[j - 1]);    
    
    close(fd);
    if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
        
    while (--j > 0)
		free(lineadress[j - 1]);
 
    
    return (0);
}