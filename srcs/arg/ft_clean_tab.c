/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tab.c                                     :+:      :+:    :+:   */
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
**	- 'char        **ft_clean_tab(char **tab, int argc)':	Clean the tab's
**	variable by  keeping the first number.
**	exemple: tab[1] = "12 45 8 9"  ==> tab[1] = "12"
*/

char		**ft_clean_tab(char **tab, int argc)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (i < argc)
	{
		y = 0;
		while (tab[i][y] != '\0')
		{
			if (tab[i][y] == '+' || tab[i][y] == '-' || tab[i][y] == ' ')
				y++;
			while (ft_isdigit(tab[i][y]))
				y++;
			tab[i][y] = '\0';
		}
		i++;
	}
	return (tab);
}
