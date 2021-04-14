/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

static void		push_first_quartile(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;
	int			end;

	end = 0;
	tmp_a = lst_a->first;
	while (tmp_a != NULL)
	{
		if (tmp_a->number <= lst_a->q_one)
			end++;
		tmp_a = tmp_a->next;
	}
	tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number <= lst_a->q_one)
		{
			if (lst_b->first && lst_b->first->number > lst_a->q_one / 2)
				ft_do_rb(lst_b);
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		tmp_a = lst_a->first;
	}
}

static void		push_second_quartile(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;
	int			end;

	tmp_a = lst_a->first;
	end = 0;
	while (tmp_a != NULL)
	{
		if (tmp_a->number > lst_a->q_one && tmp_a->number <= lst_a->median)
			end++;
		tmp_a = tmp_a->next;
	}
	tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number > lst_a->q_one && tmp_a->number <= lst_a->median)
		{
			if (lst_b->first && lst_b->first->number > (lst_a->median / 4) * 3)
				ft_do_rb(lst_b);
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		tmp_a = lst_a->first;
	}
}

static void		push_third_quartile(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;
	int			end;

	tmp_a = lst_a->first;
	end = 0;
	while (tmp_a != NULL)
	{
		if (tmp_a->number > lst_a->median && tmp_a->number <= lst_a->q_three)
			end++;
		tmp_a = tmp_a->next;
	}
	tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number > lst_a->median && tmp_a->number <= lst_a->q_three)
		{
			if (lst_b->first && lst_b->first->number > (lst_a->median / 4) * 7)
				ft_do_rb(lst_b);
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		tmp_a = lst_a->first;
	}
}

static void		push_last_quartile(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;
	int			end;

	tmp_a = lst_a->first;
	end = 0;
	while (tmp_a != NULL)
	{
		if (tmp_a->number > lst_a->q_three)
			end++;
		tmp_a = tmp_a->next;
	}
	tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number > lst_a->q_three)
		{
			if (lst_b->first && lst_b->first->number > (lst_a->median / 4) * 5)
				ft_do_rb(lst_b);
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		tmp_a = lst_a->first;
	}
}

int				sort_big(int nbr, t_data *lst_a, t_data *lst_b)
{
	lst_a->count_ra = 0;
	ft_find_mediane(nbr, lst_a);
	ft_display_info(nbr, lst_a, lst_b);
	push_first_quartile(lst_a, lst_b);
	sort_b_to_a(lst_a, lst_b);
	ft_rotate_count(lst_a);
	push_second_quartile(lst_a, lst_b);
	while (lst_a->first->number != lst_a->q_one)
		ft_do_ra(lst_a);
	ft_do_ra(lst_a);
	sort_b_to_a(lst_a, lst_b);
	ft_rotate_count(lst_a);
	ft_display_lst(lst_a, lst_b);
	push_third_quartile(lst_a, lst_b);
	while (lst_a->first->number != lst_a->median)
		ft_do_ra(lst_a);
	ft_do_ra(lst_a);
	sort_b_to_a(lst_a, lst_b);
	ft_rotate_count(lst_a);
	push_last_quartile(lst_a, lst_b);
	sort_b_to_a(lst_a, lst_b);
	ft_last_turn(nbr, lst_a, lst_b);
	return (0);
}
