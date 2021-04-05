/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

/*
**	FONCTION UTILISEE POUR AFFICHER LES LISTES PENDANT LA PERIODE DE PRODUCTION
**			n'est pas a la norme
**			doit etre supprime
**
**	==> creer une fonction d'affichage a la fin du programme!!!!!
*/

int				ft_display_lst(t_data *listA, t_data *listB)
{
	if (listA == NULL || listB == NULL)
		return (1);
	t_list		*tmp_a = listA->first;
	t_list		*tmp_b = listB->first;

	int len_a = ft_lstsize(listA->first);
	int len_b;
	if (listB->first == NULL)   //cas liste B est vide genre init
	{
		//printf("Liste B est NULL\n");
		len_b = 0;
		
	}
	else
	{
		//printf("liste B est different de nul\n");
		len_b = ft_lstsize(listB->first);
	}
	if (listB->first == NULL)			// cas 1 liste b = Null donc affiche liste a
	{
		while (tmp_a != NULL)
		{
			printf("c1\t%d  \n", tmp_a->number);
			tmp_a = tmp_a->next;
			
		}
	}
	else if (len_a >= len_b) //cas 2 les deux listes existent et a > b
	{
		//printf("len_a=%d >= len_b=%d\n", len_a, len_b);
		while (len_b > 0)
		{
			printf("c2\t%d %d\n", tmp_a->number, tmp_b->number);
			tmp_b = tmp_b->next;
			tmp_a = tmp_a->next;
			len_b--;
			len_a--;
		}
		while (len_a > 0)
		{
			printf("c3\t%d  \n", tmp_a->number);
			tmp_a = tmp_a->next;
			len_a--;
		}
	}
	else if (len_b > len_a) // cas 3 les deux listes existent et b > a
	{
		//printf("len_b=%d > len_a=%d\n", len_b, len_a);
		while (len_a > 0)
		{
			printf("c4\t%d %d\n", tmp_a->number, tmp_b->number);
			tmp_b = tmp_b->next;
			tmp_a = tmp_a->next;
			len_b--;
			len_a--;
		}
		while (len_b > 0)
		{
			printf("c3\t  %d\n", tmp_b->number);
			tmp_b = tmp_b->next;
			len_b--;
		}
	}
	//printf("  \t_ _\n");
	//printf("  \ta b\n");
	return (0);
}
