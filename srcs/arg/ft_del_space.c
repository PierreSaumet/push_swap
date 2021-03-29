/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

/*
**	This file contains 1 function:
**	- 'char        **ft_del_space(char **tab, int argc)':	If it find a space
**	character from a string, delete it.
*/

char		**ft_del_space(char **tab, int argc)
{
	int		i;
	int		y;

	i = 0;
	while (i < argc)
	{
		y = 0;
		while (tab[i][y] != '\0')
		{
			if (ft_isdigit(tab[i][y]) || tab[i][y] == '-')
				y++;
			else
			{
				while (tab[i][y] != '\0')
				{
					tab[i][y] = tab[i][y + 1];
					y++;
				}
			}
		}
		tab[i][y] = '\0';
		i++;
	}
	return (tab);
}
