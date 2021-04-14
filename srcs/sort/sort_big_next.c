/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static int			ft_min_vs_max(t_data *lst, int diff_min, int diff_max)
{
	if (diff_max < diff_min)
	{
		if (ft_find_big(lst) <= (ft_len_list(lst) / 2))
			while (ft_find_big(lst) != 1)
				ft_do_rb(lst);
		else
			while (ft_find_big(lst) != 1)
				ft_do_rrb(lst);
	}
	else
	{
		if (ft_find_small(lst) <= (ft_len_list(lst) / 2))
			while (ft_find_small(lst) != 1)
				ft_do_rb(lst);
		else
			while (ft_find_small(lst) != 1)
				ft_do_rrb(lst);
	}
	return (0);
}

static int			ft_diff_to_find(t_data *lst)
{
	int				diff_min;
	int				diff_max;

	if (ft_find_small(lst) > (ft_len_list(lst) / 2))
		diff_min = ft_len_list(lst) - ft_find_small(lst);
	else
		diff_min = ft_find_small(lst);
	if (ft_find_big(lst) > (ft_len_list(lst) / 2))
		diff_max = ft_len_list(lst) - ft_find_big(lst);
	else
		diff_max = ft_find_big(lst);
	ft_min_vs_max(lst, diff_min, diff_max);
	return (0);
}

static int			ft_find_best_big(t_data *lst)
{
	if (lst == NULL)
		return (1);
	if (ft_len_list(lst) == 1)
		return (-1);
	if (ft_find_small(lst) < (ft_len_list(lst) / 2)
			&& ft_find_big(lst) < (ft_len_list(lst) / 2))
		ft_do_rb(lst);
	else if (ft_find_small(lst) > (ft_len_list(lst) / 2)
			&& ft_find_big(lst) > (ft_len_list(lst) / 2))
		ft_do_rrb(lst);
	else
		ft_diff_to_find(lst);
	return (0);
}

int					sort_b_to_a(t_data *lst_a, t_data *lst_b)
{
	t_list			*tmp_b;

	tmp_b = lst_b->first;
	while (tmp_b != NULL)
	{
		if (ft_find_small(lst_b) == 1)
		{
			ft_do_pa(lst_a, lst_b);
			ft_do_ra(lst_a);
		}
		else if (ft_find_big(lst_b) == 1)
		{
			ft_do_pa(lst_a, lst_b);
			lst_a->count_ra++;
		}
		else
		{
			if (ft_find_best_big(lst_b) == -1)
				ft_do_pa(lst_a, lst_b);
		}
		tmp_b = lst_b->first;
	}
	return (0);
}

int					ft_rotate_count(t_data *lst_a)
{
	while (lst_a->count_ra >= 0)
	{
		ft_do_ra(lst_a);
		lst_a->count_ra--;
	}
	return (0);
}
