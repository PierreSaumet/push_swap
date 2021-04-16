/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init_insert.c                                  :+:      :+:    :+:   */
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
**	-'t_data	*initialize_listb(void)':	Inits the stack B.
**	-'int	ft_full_insertion(t_data *lst_a, int nbr, char **argv)':
**		Insert all numbers from the arguments into the stack A.
**	-'t_data	*initialize_list(int argc, char **argv)': Inits the stack A
*/

t_data			*initialize_listb(void)
{
	t_data *lst;

	if (!(lst = malloc(sizeof(t_data))))
		return (NULL);
	lst->first = NULL;
	lst->last = NULL;
	return (lst);
}

int				ft_full_insertion(t_data *lst_a, int nbr, char **argv)
{
	t_list	*new;

	new = NULL;
	while (nbr > 0)
	{
		if (!(new = malloc(sizeof(t_list))))
			return (1);
		new->number = atoi(argv[nbr - 1]);
		new->next = lst_a->first;
		new->prev = NULL;
		if (lst_a->first)
			lst_a->first->prev = new;
		else
			lst_a->last = new;
		lst_a->first = new;
		nbr--;
	}
	return (0);
}

t_data			*initialize_list(int argc, char **argv)
{
	t_data		*list;
	t_list		*element;

	if (!(list = malloc(sizeof(t_data))))
		return (NULL);
	if (!(element = malloc(sizeof(t_list))))
		return (NULL);
	element->number = atoi(argv[argc - 1]);
	element->next = NULL;
	element->prev = NULL;
	list->first = element;
	list->last = element;
	return (list);
}
