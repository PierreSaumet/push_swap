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

t_data			*initialize_listb(void)
{
	t_data *lst;

	if (!(lst = malloc(sizeof(t_data))))
		return (NULL);
	lst->first = NULL;
	lst->last = NULL;
	return (lst);
}

int				ft_insertion(t_data *lst_a, int nbr)
{
	t_list		*new;

	if (!(new = malloc(sizeof(t_list))))
		return (1);
	new->number = nbr;
	new->next = lst_a->first;
	new->prev = NULL;
	if (lst_a->first)
		lst_a->first->prev = new;
	else
		lst_a->last = new;
	lst_a->first = new;
	return (0);
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
