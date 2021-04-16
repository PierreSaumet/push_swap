/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 4 functions, all used for freeing:
**	-'void	ft_free_tab(char **tab, int nbr)':	Free the tab used to free
**	the data passing by arguments.
**	-'int	ft_lstsize(t_list *lst)':	Count the elements of the list.
**	-'static int	ft_delete_first(t_data *lst_a)':	Deletes the first
**	item of the given list.
**	-'int	ft_free_all(t_data *lst_a, t_data *lst_b)':
**		Free the two stacks, A and B.
*/

void		ft_free_tab(char **tab, int nbr)
{
	int		i;

	i = 0;
	while (i < nbr)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

int			ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int	ft_delete_first(t_data *lst_a)
{
	t_list *to_del;

	if (lst_a == NULL)
		exit(EXIT_FAILURE);
	if (lst_a->first != NULL)
	{
		to_del = lst_a->first;
		lst_a->first = lst_a->first->next;
		free(to_del);
	}
	return (0);
}

int			ft_free_all(t_data *lst_a, t_data *lst_b)
{
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(lst_a->first);
	len_b = ft_lstsize(lst_b->first);
	while (len_a > 0)
	{
		ft_delete_first(lst_a);
		len_a--;
	}
	while (len_b > 0)
	{
		ft_delete_first(lst_b);
		len_b--;
	}
	free(lst_a);
	free(lst_b);
	return (0);
}
