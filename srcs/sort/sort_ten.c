/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**  This file contains 4 functions:
**  -'int   sort_middle(int nbr, t_data *lst_a, t_data *lst_b)':    choose
**  between the different algo according to the amount of numbers.
**  -'static int   solve_5(int nbr, t_data *lst_a, t_data *lst_b)': solve
**  5 numbers.
**  -'static int   solve_4(int nbr, t_data *lst_a, t_data *lst_b)': solve
**  4 numbers.
**  -'static int    ft_do(int nbr, t_data *lst_a, t_data *lst_b)':  push
**  into stack B, solve and push into stack A.
*/

static int			ft_do(int nbr, t_data *lst_a, t_data *lst_b)
{
	ft_do_pb(lst_a, lst_b);
	sort_small(nbr - 1, lst_a);
	ft_do_pa(lst_a, lst_b);
	return (0);
}

static int			solve_4(int nbr, t_data *lst_a, t_data *lst_b)
{
	if (ft_find_small(lst_a) == 1)
		ft_do(nbr, lst_a, lst_b);
	else if (ft_find_small(lst_a) == 4)
	{
		ft_do_rra(lst_a);
		if (ft_end(lst_a, lst_b) == 1)
			ft_do(nbr, lst_a, lst_b);
	}
	else if (ft_find_small(lst_a) == 3)
	{
		ft_do_rra(lst_a);
		ft_do_rra(lst_a);
		if (ft_end(lst_a, lst_b) == 1)
			ft_do(nbr, lst_a, lst_b);
	}
	else if (ft_find_small(lst_a) == 2)
	{
		ft_do_ra(lst_a);
		if (ft_end(lst_a, lst_b) == 1)
			ft_do(nbr, lst_a, lst_b);
	}
	return (0);
}

static int			solve_5(int nbr, t_data *lst_a, t_data *lst_b)
{
	t_list			*tmp;
	int				end;

	ft_find_mediane(nbr, lst_a);
	tmp = lst_a->first;
	end = 0;
	while (tmp && end < 2)
	{
		if (tmp->number < lst_a->median)
		{
			ft_do_pb(lst_a, lst_b);
			end++;
		}
		else
			ft_do_ra(lst_a);
		tmp = lst_a->first;
	}
	sort_small(ft_len_list(lst_a), lst_a);
	if (lst_b->first->number < lst_b->last->number)
		ft_do_sb(lst_b);
	ft_do_pa(lst_a, lst_b);
	ft_do_pa(lst_a, lst_b);
	return (0);
}

int					sort_middle(int nbr, t_data *lst_a, t_data *lst_b)
{
	if (nbr == 4)
		solve_4(nbr, lst_a, lst_b);
	else if (nbr == 5)
		solve_5(nbr, lst_a, lst_b);
	else if (nbr <= 100)
		solve_middle(nbr, lst_a, lst_b);
	return (0);
}
