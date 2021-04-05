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

#include "../../headers/checker.h"

/*
**	This file contains 3 functions:
**	-'int			ft_neg_int(char *str)':	Checks if the string contains
**	INT_MIN, if bigger returns EXIT_FAILURE.
**	-'int			ft_int(char *str)':	Checks if the string contains INT_MAX,
**	if bigger returns EXIT_FAILURE.
**	-'int			ft_check_int(char **tab, int argc)':	Checks if it's a
**	negative integer or positive.
*/

int			ft_neg_int(char *str)
{
	if (strlen(str) >= 12)
	{
		printf("ERREUR\n");
		exit(EXIT_FAILURE);
	}
	if (strlen(str) == 11)
	{
		if (strcmp(str, "-2147483648") > 0)
		{
			printf("ERREUR\n");
			exit(EXIT_FAILURE);
		}
		printf("STRCMOP = %d\n", strcmp(str, "-2147483648"));
		return (0);
	}
	return (0);
}

int			ft_int(char *str)
{
	if (strlen(str) >= 11)
	{
		printf("ERREUR\n");
		exit(EXIT_FAILURE);
	}
	if (strlen(str) == 10)
	{
		if (strcmp(str, "2147483647") > 0)
		{
			printf("ERREUR\n");
			exit(EXIT_FAILURE);
		}
		printf("STRCMOP = %d\n", strcmp(str, "2147483647"));
		return (0);
	}
	return (0);
}

int			ft_check_int(char **tab, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (tab[i][0] == '-')
		{
			//printf("Go minus\n");
			ft_neg_int(tab[i]);
		}
		else
		{
			//printf("go big\n");
			ft_int(tab[i]);
		}
		i++;
	}
	return (0);
}
