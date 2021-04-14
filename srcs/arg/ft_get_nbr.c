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

#include "../../headers/push_swap.h"

/*
**  This File contains 5 functions
*/

int				ft_end(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;

	tmp_a = lst_a->first;
	if (lst_b->first == NULL)
	{
		while (tmp_a->next != NULL)
		{
			if (tmp_a->number > tmp_a->next->number)
				return (1);
			tmp_a = tmp_a->next;
		}
		return (0);
	}
	printf("ERREUR LIST2 PAS VIDE\n");
	exit(EXIT_FAILURE);
	return (2);
}

unsigned int	ft_get_len(int argc, char **argv)
{
	unsigned int	len;
	int				i;

	i = 1;
	len = strlen(argv[i]);
	while (i < argc)
	{
		if (len < strlen(argv[i]))
			len = strlen(argv[i]);
		i++;
	}
	return (len);
}

char			**ft_malloc_tab(int nbr, int argc, char **argv)
{
	char		**tab;
	int			len;
	int			i;

	len = 0;
	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (nbr + 1))))
		exit(EXIT_FAILURE);
	len = ft_get_len(argc, argv);
	while (i < nbr)
	{
		if (!(tab[i] = malloc(sizeof(char *) * len)))
			exit(EXIT_FAILURE);
		i++;
	}
	return (tab);
}

char			**ft_get_nbr(int argc, char **argv, char **tab, int nbr)
{
	int			i;

	i = 0;
	while (argc > 0)
	{
		i = strlen(argv[argc]);
		while (i-- >= 0)
		{
			if (ft_isdigit(argv[argc][i]))
			{
				if (argv[argc][i - 1] == ' ' || argv[argc][i - 1] == '-'
						|| argv[argc][i - 1] == '+' || i == 0)
				{
					if (i == 0)
						strcpy(tab[nbr - 1], &argv[argc][i]);
					else
						strcpy(tab[nbr - 1], &argv[argc][i - 1]);
					nbr--;
				}
			}
		}
		argc--;
	}
	return (tab);
}
