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

#include "headers/push_swap.h"

/*
**  This file is the main file for the 'PUSH_SWAP' program
**  It contains 4 functions
**  -'int         ft_push_swap(int nbr, t_data *lst_a, t_data *lst_b)':
**      Different algorithms depending on the number of digits
**  -'int        ft_start(int nbr, char **argv)':   Inits 2 stacks and starts
**  the push swap program's.
**  -'void    ft_initialize(int nbr, int argc, char **argv)': find all numbers
**  from the arguments, even lists.
**  -'int     main(int argc, char **argv)': Starts the program.
*/

int				ft_push_swap(int nbr, t_data *lst_a, t_data *lst_b)
{
	lst_a->nbr = nbr;
	lst_b->nbr = nbr;
	if (nbr <= 3)
		sort_small(nbr, lst_a);
	else if (nbr <= 100)
		sort_middle(nbr, lst_a, lst_b);
	else
		sort_big(nbr, lst_a, lst_b);
	return (0);
}

int				ft_start_pw(int nbr, char **argv)
{
	t_data		*lst_a;
	t_data		*lst_b;

	lst_a = initialize_list(nbr, argv);
	lst_b = initialize_listb();
	ft_full_insertion(lst_a, nbr - 1, argv);
	if (ft_end(lst_a, lst_b) == 1)
	{
		ft_push_swap(nbr, lst_a, lst_b);
	}
	ft_free_all(lst_a, lst_b);
	return (0);
}

void			ft_initialize_pw(int nbr, int argc, char **argv)
{
	char		**tab;

	tab = NULL;
	tab = ft_malloc_tab(nbr, argc, argv);
	tab = ft_get_nbr(argc - 1, argv, tab, nbr);
	tab = ft_clean_tab(tab, nbr);
	tab = ft_del_space(tab, nbr);
	tab = ft_check_zero(tab, nbr, 0, 0);
	if (ft_check_int(tab, nbr) == 0)
		if (ft_duplicate(tab, nbr) == 0)
			ft_start_pw(nbr, tab);
	ft_free_tab(tab, nbr);
}

int				main(int argc, char **argv)
{
	int			ret;

	ret = ft_check_args(argc - 1, argv, 0);
	if (ret == 1)
		return (1);
	else
	{
		ret = ft_count(argc, argv, 0);
		if (ret == 0)
			return (1);
		ft_initialize_pw(ret, argc, argv);
	}
	return (0);
}
