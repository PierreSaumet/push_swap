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

#include "../../headers/checker.h"



// verifie que la liste est trie du + grand au plus petit
int         ft_ordre_decroissant(t_data *lst_a, t_data *lst_b)
{
	t_list  *tmp_a;

	tmp_a = lst_a->first;
	(void)lst_b;
	while (tmp_a->next != NULL)
	{
		if (tmp_a->number < tmp_a->next->number)
			return (1);
		tmp_a = tmp_a->next;
	}
	return (0);

}

// Verifie que toute la liste est ranger en ordre croissant 
// Si oui, return 0 si il y a une erreur retourne 1
int         ft_ordre_croissant(t_data *lst_a, t_data *lst_b)    // dans la liste a
{
	t_list  *tmp_a;

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

// Verifie que la liste est ranger en ordre croissant apres le premier item
// Si oui, return 0 si il y a une erreur retourne 1
int         ft_semi_order(t_data *lst)    // 
{
	t_list  *tmp_a;

    //printf("dans ft_semi order\n");
	tmp_a = lst->first->next;
	while (tmp_a->next != NULL)
	{
		if (tmp_a->number > tmp_a->next->number)
			return (1);
		tmp_a = tmp_a->next;
	}
	return (0);

}

int         ft_len_lst(t_data *lst)
{
    t_list *tmp;
    int     i;

    i = 0;
    tmp = lst->first;
    while (tmp)
    {
        i++;
        tmp = tmp->next;
    }
    //printf("i = %d\n", i);
    return (i);
}


int			other(int nbr, t_data *lst_a, t_data *lst_b)
{
    test(nbr, lst_a, lst_b);

    printf("ici nbr = %d\n", nbr);
    return (0);
}








