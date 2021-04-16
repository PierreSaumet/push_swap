/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
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
**	-'static int	ft_neg_int(char *str)':	Checks if the string contains
**	INT_MIN, if bigger returns EXIT_FAILURE.
**	-'static int	ft_int(char *str)':	Checks if the string contains INT_MAX,
**	if bigger returns EXIT_FAILURE.
**	-'int			ft_check_int(char **tab, int argc)':	Checks if it's a
**	negative integer or positive.
*/

static int		ft_neg_int(char *str)
{
	if (strlen(str) >= 12)
	{
		printf("Error\n");
		return (1);
	}
	if (strlen(str) == 11)
	{
		if (strcmp(str, "-2147483648") > 0)
		{
			printf("Error\n");
			return (1);
		}
		return (0);
	}
	return (0);
}

static int		ft_int(char *str)
{
	if (strlen(str) >= 11)
	{
		printf("Error\n");
		return (1);
	}
	if (strlen(str) == 10)
	{
		if (strcmp(str, "2147483647") > 0)
		{
			printf("Error\n");
			return (1);
		}
		return (0);
	}
	return (0);
}

int				ft_check_int(char **tab, int argc)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (i < argc)
	{
		if (tab[i][0] == '-')
			ret = ft_neg_int(tab[i]);
		else
			ret = ft_int(tab[i]);
		if (ret == 1)
			return (1);
		i++;
	}
	return (0);
}
