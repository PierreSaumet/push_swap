/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 3 functions:
**	- 'static int	ft_is_fullzero(char *str)':	Checks if the string contains
**	only '0', if yes return 0.
**	- 'static char	**ft_is_zero(char **tab, int nbr)': Puts '0'.
**	- 'char		**ft_check_zero(char **tab, int nbr, int i, int y)':	Replace
**	all 0, delete them.
*/

int					ft_is_fullzero(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

static char			**ft_is_zero(char **tab, int nbr)
{
	int				i;

	i = 0;
	while (i < nbr)
	{
		if (ft_is_fullzero(tab[i]) == 0)
		{
			tab[i][0] = '0';
			tab[i][1] = '\0';
		}
		i++;
	}
	return (tab);
}

char				**ft_check_zero(char **tab, int nbr, int i, int y)
{
	int				k;

	k = 0;
	while (i < nbr)
	{
		y = 0;
		k = 0;
		if (tab[i][0] == '0' && ft_strlen(tab[i]) > 1
				&& ft_is_fullzero(tab[i]) == 1)
		{
			while (tab[i][y] == '0')
				y++;
			while (tab[i][y])
			{
				tab[i][k] = tab[i][y];
				y++;
				k++;
			}
			tab[i][k] = '\0';
		}
		i++;
	}
	tab = ft_is_zero(tab, nbr);
	return (tab);
}
