/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
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
**	-'int     ft_ra(t_data *lst_a)':	Rotates all the stack A, the first one
**	becomes the last.
**	-'int     ft_rb(t_data *lst_b)':	Same thing but with the stack B
*/

int				ft_do_ra(t_data *lst_a)
{
	ft_ra(lst_a);
	write(1, "ra\n", 3);
	lst_a->total++;
	return (0);
}

int				ft_do_rb(t_data *lst)
{
	ft_rb(lst);
	write(1, "rb\n", 3);
	lst->total++;
	return (0);
}

int				ft_ra(t_data *lst_a)
{
	t_list	*tmp_a;
	int		tmp_nbr;

	if (lst_a == NULL)
		exit(EXIT_FAILURE);
	if (ft_lstsize(lst_a->first) <= 1)
	{
		printf("la liste A contient 1 ou 0 elem\n");
		return (0);
	}
	tmp_a = lst_a->first;
	tmp_nbr = tmp_a->number;
	while (tmp_a->next != NULL)
	{
		tmp_a->number = tmp_a->next->number;
		tmp_a = tmp_a->next;
	}
	tmp_a->number = tmp_nbr;
	return (0);
}

int				ft_rb(t_data *lst_b)
{
	t_list	*tmp_b;
	int		tmp_nbr;

	if (lst_b == NULL)
		exit(EXIT_FAILURE);
	if (ft_lstsize(lst_b->first) <= 1)
	{
		printf("la liste A contient 1 ou 0 elem\n");
		return (0);
	}
	tmp_b = lst_b->first;
	tmp_nbr = tmp_b->number;
	while (tmp_b->next != NULL)
	{
		tmp_b->number = tmp_b->next->number;
		tmp_b = tmp_b->next;
	}
	tmp_b->number = tmp_nbr;
	return (0);
}
