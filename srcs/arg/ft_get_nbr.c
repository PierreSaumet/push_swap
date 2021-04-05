/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

/*
**  This File contains 5 functions
*/

unsigned int ft_get_len(int argc, char **argv)  // longueur max des arguments
{
    unsigned int len;
    int i;

    i = 1;
    len = strlen(argv[i]);
    
    while (i < argc)
    {
        if (len < strlen(argv[i]))
            len = strlen(argv[i]);
        i++;
    }
    //printf("\n LA LONGUEUR MAX = %d\n", len);
    return (len);
}

char    **ft_malloc_tab(int nbr, int argc, char **argv)
{
    char    **tab;
    int     len;
    int     i;

    len = 0;
    i = 0;
    if (!(tab = (char **)malloc(sizeof(char *) * (nbr + 1))))
        exit(EXIT_FAILURE);
    len = ft_get_len(argc, argv);
    while (i < nbr)                 // malloc notre tablea
    {
        if (!(tab[i] = malloc(sizeof(char *) * len)))
            exit(EXIT_FAILURE);
        i++;
    }
    //printf("ici\n");
    return (tab);
}


char    **ft_get_nbr(int argc, char **argv, char **tab, int nbr)
{
    int i;
    
    i = 0;
    while (argc > 0)        // on debute du dernier argument
    {
        i = strlen(argv[argc]);         // la longueur de l'arguement
        while (i >= 0)           // on parcourt l'argument
        {
            if (argv[argc][i] == '\0')          // si nfin de chaine
                i--;
            else if (ft_isdigit(argv[argc][i]))      //si c'est un chiffre
            {
                if (argv[argc][i - 1] == ' ' || argv[argc][i - 1] == '-'
                        || argv[argc][i - 1] == '+' || i == 0)        // si -1 = + ou - ou ' '
                {
                    if (i == 0)
                        strcpy(tab[nbr - 1], &argv[argc][i]);
                    else
                        strcpy(tab[nbr - 1], &argv[argc][i - 1]);
                    nbr--;
                }
                i--;      
            }
            else
                i--;
        }
        argc--;
    }
    return (tab);
}