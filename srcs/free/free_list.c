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

#include "../../headers/checker.h"

void    ft_free_tab(char **tab, int nbr)
{
    int i = 0;
    while (i < nbr)
    {
        free(tab[i]);
        tab[i] = NULL;
        i++;
    }
    free(tab);
}

int	ft_lstsize(t_list *lst)
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


int        ft_delete_first(t_data *listA)
{
    t_list *to_del;
    if (listA == NULL)
        exit (EXIT_FAILURE);
    if (listA->first != NULL)
    {
        to_del = listA->first;
        listA->first = listA->first->next;
        free(to_del);
    }
    return (0);
}

int    ft_free_all(t_data *lst_a, t_data *lst_b)
{
    int len_a;
    int len_b;

    len_a = ft_lstsize(lst_a->first);
    len_b = ft_lstsize(lst_b->first);
    printf("dans free all: len_a=%d et len_b=%d\n", len_a, len_b);
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

