/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 1 function:
**	-'int		ft_duplicate(char **tab, int nbr)':	Copy the tab
*/

int		ft_duplicate(char **tab, int nbr)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < nbr)
	{
		j = 1;
		while (j < nbr)
		{
			if (strcmp(tab[i], tab[j]) == 0 && i != j)
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
