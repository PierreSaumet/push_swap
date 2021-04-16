/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 5 functions:
**	-'int	ft_find_best(int nbr, t_data *lst, int div)':	find where are the
**	smallest and biggest numbers in the stack and the best play to do, rotate
**	or reverse rotate.
**	-'static int	ft_end_find_best(int diff_min, int diff_max, t_data *lst:
**  find if it should put the biggest or smallest number at the top.
**  -'int   ft_ascending(t_data *lst_a, t_data *lst_b)':    checks if the list
**  is arranged in ascending order, return 1 if not.
**  -'static void  sort_array(long *array, int nbr)':       sort the long-array
**  in ascending order. Use for finding the median.
**  -'int   ft_find_mediane(int nbr, t_data *lst)':         Find the mediane
**  the first quartile and the third quartile of the list.
*/

static int		ft_end_find_best(int diff_min, int diff_max, t_data *lst,
		int div)
{
	if (diff_min > diff_max)
	{
		if (ft_find_small(lst) < (lst->nbr / div))
			ft_do_rb(lst);
		else
			ft_do_rrb(lst);
	}
	else
	{
		if (ft_find_big(lst) < (lst->nbr / div))
			ft_do_rb(lst);
		else
			ft_do_rrb(lst);
	}
	return (0);
}

int				ft_find_best(int nbr, t_data *lst, int div)
{
	int			diff_min;
	int			diff_max;

	if (lst == NULL)
		return (1);
	diff_min = ft_find_small(lst) - nbr;
	diff_max = ft_find_big(lst) - nbr;
	if (ft_len_list(lst) == 1)
		return (-1);
	if (ft_find_small(lst) < (nbr / div) && ft_find_big(lst) < (nbr / div))
		ft_do_rb(lst);
	else if (ft_find_small(lst) > (nbr / div) && ft_find_big(lst) > (nbr / div))
		ft_do_rrb(lst);
	else
		ft_end_find_best(diff_min, diff_max, lst, div);
	return (0);
}

int				ft_ascending(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;

	tmp_a = lst_a->first;
	(void)lst_b;
	while (tmp_a->next != NULL)
	{
		if (tmp_a->number > tmp_a->next->number)
			return (1);
		tmp_a = tmp_a->next;
	}
	return (0);
}

static void		sort_array(long *array, int nbr)
{
	long		tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (i < nbr - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

int				ft_find_mediane(int nbr, t_data *lst)
{
	t_list		*tmp;
	long		*array;
	int			i;
	int			q;

	tmp = lst->first;
	i = 0;
	q = nbr / 4;
	if (!(array = (long *)malloc(sizeof(long) * (nbr + 1))))
		exit(EXIT_FAILURE);
	while (i < nbr)
	{
		array[i++] = tmp->number;
		tmp = tmp->next;
	}
	sort_array(array, nbr);
	lst->q_one = array[q];
	lst->median = array[q * 2];
	lst->q_three = array[q * 3];
	free(array);
	return (0);
}
