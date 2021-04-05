/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/checker.h"

/*
**  This file is the main file for the 'PUSH_SWAP' program
**  It contains 5 functions
**  -'int         ft_end(t_data *lst_a, t_data *lst_b)':    Checks if numbers
**  are sorted. 1 / 5 / 78/ 125
**  -'int         ft_push_swap(int nbr, t_data *lst_a, t_data *lst_b)':
**      Different algorithms depending on the number of digits
**  -'int        ft_start(int nbr, char **argv)':   Inits 2 stacks and starts
**  the push swap program's.
**  -'void    ft_initialize(int nbr, int argc, char **argv)': find all numbers
**  from the arguments, even lists.
**  -'int     main(int argc, char **argv)': Starts the program.
*/

int         ft_end(t_data *lst_a, t_data *lst_b)
{
	t_list  *tmp_a;

	tmp_a = lst_a->first;
	if (lst_b->first == NULL)   // a marche
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

int         ft_push_swap(int nbr, t_data *lst_a, t_data *lst_b)
{
	if (nbr <= 3)
	{
		//printf("Inferieur ou egal 3\n");

		nbr_three(nbr, lst_a, lst_b);
	}
	else if (nbr <= 10)
	{
		nbr_ten(nbr, lst_a, lst_b);
	   // printf("Inferieur ou egal a 10\n");
	}
	else if (nbr <= 100)
	{
		printf("Inferieur ou egal a 100\n");
	}
	else if (nbr <= 500)
	{
		printf("Inferieur ou egal a 500\n");
	}
	else if (nbr <= 1000)
	{
		printf("Inferieur ou egal a 1000\n");
	}
	else
	{
		printf("superieur a 1000\n");
	}

	return (0);
}

int        ft_start(int nbr, char **argv)
{
	t_data      *lst_a;
	t_data      *lst_b;

	lst_a = initialize_list(nbr, argv);
	lst_b = initialize_listb();
	ft_full_insertion(lst_a, nbr - 1, argv);



	// test algorithme de tri par selection
	//
	// SEULEMENT PUSH SWAP
	if (ft_end(lst_a, lst_b) == 1)
	{
		ft_push_swap(nbr, lst_a, lst_b);
	}

	///////////////////////////////////
	printf("\n\nFIN\n");
	ft_display_lst(lst_a, lst_b);
	ft_free_all(lst_a, lst_b);     
	return (0);            
}

void    ft_initialize(int nbr, int argc, char **argv)
{
	char **tab;

	tab = NULL;
	tab = ft_malloc_tab(nbr, argc, argv);
	tab = ft_get_nbr(argc - 1, argv, tab, nbr);
	tab = ft_clean_tab(tab, nbr);
	tab = ft_del_space(tab, nbr);
	tab =ft_check_zero(tab, nbr, 0, 0);
	ft_check_int(tab, nbr);
	ft_duplicate(tab, nbr);

	// START THE PROGRAMME then free the numbers 
	ft_start(nbr, tab);
	ft_free_tab(tab, nbr);
}

int     main(int argc, char **argv)
{
	int ret;

	ret = ft_check_args(argc, argv, 0);
	if (ret == 1)
		return (1);
	else
	{
		ret = ft_count(argc, argv);
		if (ret == 0)
			return (1);
		ft_initialize(ret, argc, argv);  
	}
	return (0);
}