/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 4 functions:
**	-'int	ft_do_rra(t_data *lst_a)':	Do the associate function, write it
**	in the stdout and count the action.
**	-'int	ft_do_rrb(t_data *lst)':	Do the associate function, write it
**	in the stdout and count the action.
**	-'int	ft_rra(t_data *lst_a)':		Rotates the stack A from the end.
**	The last one becomes the first one. The first ==> second.
**	-'int	ft_rrb(t_data *lst_b)':		Same as above but with the stack B.
*/

int				ft_do_rra(t_data *lst_a)
{
	ft_rra(lst_a);
	write(1, "rra\n", 4);
	lst_a->total++;
	return (0);
}

int				ft_do_rrb(t_data *lst_b)
{
	ft_rrb(lst_b);
	write(1, "rrb\n", 4);
	lst_b->total++;
	return (0);
}

int				ft_rra(t_data *lst_a)
{
	t_list	*tmp_a;
	int		tmp_nbr;

	if (lst_a == NULL)
		exit(EXIT_FAILURE);
	if (ft_lstsize(lst_a->first) <= 1)
	{
		return (0);
	}
	tmp_a = lst_a->last;
	tmp_nbr = tmp_a->number;
	(void)tmp_nbr;
	while (tmp_a->prev != NULL)
	{
		tmp_a->number = tmp_a->prev->number;
		tmp_a = tmp_a->prev;
	}
	tmp_a->number = tmp_nbr;
	return (0);
}

int				ft_rrb(t_data *lst_b)
{
	t_list	*tmp_b;
	int		tmp_nbr;

	if (lst_b == NULL)
		exit(EXIT_FAILURE);
	if (ft_lstsize(lst_b->first) <= 1)
		return (0);
	tmp_b = lst_b->last;
	tmp_nbr = tmp_b->number;
	(void)tmp_nbr;
	while (tmp_b->prev != NULL)
	{
		tmp_b->number = tmp_b->prev->number;
		tmp_b = tmp_b->prev;
	}
	tmp_b->number = tmp_nbr;
	return (0);
}
