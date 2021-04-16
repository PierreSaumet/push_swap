/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**  This file contains 5 functions, used for sorting 100 numbers max.
**	-'int	solve_middle(int nbr, t_data *lst_a, t_data *lst_b)':	main algo
**	find the median, push number under it into Stack b, class them and repeat.
**	-'static int	ft_first_middle(t_data *lst_a, t_data *lst_b)': find all
**	numbers under the median and put them into stack B.
**	-'staticint	ft_push_to_a(int nbr, t_data *lst_a, t_data *lst_b)':
**      push the  stack B into stack A. Big numbers on the top and small
**      at the bottom.
**	-'static int	ft_push_to_b_order(t_data *lst_a, t_data *lst_b)':
**      push the number above the median into Stack B and rotate until stack A
**      is sorted.
**	-'int	ft_last_turn(int nbr, t_data *lst_a, t_data *lst_b)':	sort the
**	stack A, find if it will be by rotate or reverse rotate.
*/

static int		ft_first_middle(t_data *lst_a, t_data *lst_b, int end)
{
	t_list		*tmp_a;

	tmp_a = lst_a->first;
	while (tmp_a != NULL)
	{
		if (tmp_a->number < lst_a->median)
			end++;
		tmp_a = tmp_a->next;
	}
	tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number < lst_a->median)
		{
			if (lst_b->first && lst_b->first->number > lst_a->median / 2)
				ft_do_rb(lst_b);
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		tmp_a = lst_a->first;
	}
	return (0);
}

static int		ft_push_to_a(int nbr, t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_b;

	tmp_b = lst_b->first;
	while (tmp_b != NULL)
	{
		if (ft_find_small(lst_b) == 1)
		{
			ft_do_pa(lst_a, lst_b);
			ft_do_ra(lst_a);
		}
		else if (ft_find_big(lst_b) == 1)
			ft_do_pa(lst_a, lst_b);
		if (ft_find_best(nbr, lst_b, 4) == -1)
			ft_do_pa(lst_a, lst_b);
		tmp_b = lst_b->first;
	}
	return (0);
}

static int		ft_push_to_b_order(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;

	tmp_a = lst_a->first;
	while (ft_ascending(lst_a, lst_b) != 0)
	{
		if (tmp_a->number >= lst_a->median)
		{
			ft_do_pb(lst_a, lst_b);
		}
		else
		{
			ft_do_ra(lst_a);
		}
		tmp_a = lst_a->first;
	}
	return (0);
}

int				ft_last_turn(int nbr, t_data *lst_a, t_data *lst_b)
{
	while (ft_ascending(lst_a, lst_b) != 0)
	{
		if (ft_find_small(lst_a) <= (nbr / 2))
			ft_do_ra(lst_a);
		else
			ft_do_rra(lst_a);
	}
	return (0);
}

int				solve_middle(int nbr, t_data *lst_a, t_data *lst_b)
{
	lst_a->total = 0;
	lst_b->total = 0;
	ft_find_mediane(nbr, lst_a);
	ft_first_middle(lst_a, lst_b, 0);
	ft_push_to_a(nbr, lst_a, lst_b);
	ft_push_to_b_order(lst_a, lst_b);
	ft_push_to_a(nbr, lst_a, lst_b);
	ft_last_turn(nbr, lst_a, lst_b);
	return (0);
}
