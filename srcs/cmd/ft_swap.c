/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 2 functions:
**	-'int			ft_sa(t_data *lst_a)':	Swap the first with the second
**	element of stack A.
**	-'int			ft_sb(t_data *lst_b)':	Swap the first with the second
**	element of stack B.
*/

int				ft_do_sa(t_data *lst_a)
{
	ft_sa(lst_a);
	write(1, "sa\n", 3);
	lst_a->total++;
	return (0);
}

int				ft_do_sb(t_data *lst_b)
{
	ft_sb(lst_b);
	write(1, "sb\n", 3);
	lst_b->total++;
	return (0);
}

int				ft_sa(t_data *lst_a)
{
	t_list	*lst_tmp;
	int		tmp;

	tmp = 0;
	if (lst_a == NULL)
		return (1);
	if (lst_a->first == NULL || (ft_lstsize(lst_a->first) == 1))
		return (0);
	lst_tmp = lst_a->first;
	tmp = lst_tmp->number;
	lst_tmp->number = lst_tmp->next->number;
	lst_tmp->next->number = tmp;
	return (0);
}

int				ft_sb(t_data *lst_b)
{
	t_list	*tmp_a;
	int		tmp_nbr;

	if (lst_b == NULL)
		return (1);
	if (lst_b->first == NULL || (ft_lstsize(lst_b->first) == 1))
		return (0);
	tmp_a = lst_b->first;
	tmp_nbr = tmp_a->number;
	tmp_a->number = tmp_a->next->number;
	tmp_a->next->number = tmp_nbr;
	return (0);
}
