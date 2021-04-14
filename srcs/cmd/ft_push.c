/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 3 functions:
**	-'int	  ft_lst_empty(t_data *lst_a, t_data *lst_b)':	Checks if the
**	lists are usefull or empty.
**	-'int     ft_pb(t_data *lst_a, t_data *lst_b)':	Push the first number
**	of the stack A into the stack B, do nothing if empty.
**	-'int     ft_pa(t_data *lst_a, t_data *lst_b)':	Same thing as above, but
**	stack B into Stack A.
*/

int				ft_do_pa(t_data *lst_a, t_data *lst_b)
{
	ft_pa(lst_a, lst_b);
	write(1, "pa\n", 3);
	lst_a->total++;
	return (0);
}

int				ft_do_pb(t_data *lst_a, t_data *lst_b)
{
	ft_pb(lst_a, lst_b);
	write(1, "pb\n", 3);
	lst_a->total++;
	return (0);
}

int				ft_lst_empty(t_data *lst_a, t_data *lst_b)
{
	if (lst_a == NULL || lst_b == NULL)
		exit(EXIT_FAILURE);
	if (lst_a->first == NULL)
		return (0);
	return (1);
}

int				ft_pb(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;
	t_list		*tmp_b;

	if (ft_lst_empty(lst_a, lst_b) == 0)
		return (0);
	tmp_a = lst_a->first;
	if (!(tmp_b = malloc(sizeof(t_list))))
		exit(EXIT_FAILURE);
	tmp_b->number = tmp_a->number;
	tmp_b->next = lst_b->first;
	tmp_b->prev = NULL;
	if (lst_b->first)
		lst_b->first->prev = tmp_b;
	else
		lst_b->last = tmp_b;
	lst_b->first = tmp_b;
	lst_a->first = lst_a->first->next;
	if (lst_a->first != NULL)
		lst_a->first->prev = NULL;
	free(tmp_a);
	if (lst_a->first == NULL)
		lst_a->last = NULL;
	return (0);
}

int				ft_pa(t_data *lst_a, t_data *lst_b)
{
	t_list		*tmp_a;
	t_list		*tmp_b;

	if (lst_b->first == NULL)
		return (0);
	tmp_b = lst_b->first;
	if (!(tmp_a = malloc(sizeof(t_list))))
		exit(EXIT_FAILURE);
	tmp_a->number = tmp_b->number;
	tmp_a->next = lst_a->first;
	tmp_a->prev = NULL;
	if (lst_a->first)
		lst_a->first->prev = tmp_a;
	else
		lst_a->last = tmp_a;
	lst_a->first = tmp_a;
	lst_b->first = lst_b->first->next;
	if (lst_b->first != NULL)
		lst_b->first->prev = NULL;
	free(tmp_b);
	if (lst_b->first == NULL)
		lst_b->last = NULL;
	return (0);
}
