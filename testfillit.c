/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiralle <rmiralle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:18:32 by rmiralle          #+#    #+#             */
/*   Updated: 2018/01/31 18:20:23 by rmiralle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int     check_mistake(char *t, int size)
{
    int i;
    int p;

    i = 0;
    p = 0;
   // ft_putstr("nouvelle chaine :\n");
    
   // ft_putstr(t);

    if (t[4] != '\n' || t[9] != '\n' || t[14] != '\n' || t[19] != '\n')
        return (0);
    while (i < size)
    {
        if (t[i] != '#' && t[i] != '.' && t[i] != '\n')
            return (0);
        i++;
    }
    return(1);
}


int    main(int argc, char **argv)
{
    int i;
    int fd;
    char buf[21];
    int ret;
    

    i = 0;
    ret = -1;
    fd = open(argv[1], O_RDONLY);
    int carrotcake;

    if (argc != 2)
    {
        ft_putstr("usage: ./fillit sample_file\n");
        return (0);
    }
    while ((ret = read(fd, buf, 21)) > 0)
    {
        ft_putstr("\033[32mcarrotcake = "); // la couleur devient 32=verte 31=rouge
        if ((carrotcake = check_mistake(buf, ret)) == 0)
        {
            printf("%d\n", carrotcake);            
            return (0);
        }
        printf("%d\n", carrotcake);
       ft_putstr("\033[0m"); // la couleur devient blanche 0=blanc
       ft_putstr("\nONCHONCH\n");
                    
        
        // appeller une fonction de verification d'erreur
 //       usleep(5000);
 //       printf("%d\n", ret);
    }
    return (0);
}