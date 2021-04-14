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

#include "../../headers/push_swap.h"

/*
**	FONCTION UTILISEE POUR AFFICHER LES LISTES PENDANT LA PERIODE DE PRODUCTION
**			n'est pas a la norme
**			doit etre supprime
**
**	==> creer une fonction d'affichage a la fin du programme!!!!!
*/

int				ft_display_lst(t_data *lista, t_data *listb)
{
	t_list		*tmp_a;
	t_list		*tmp_b;
	int			len_a;
	int			len_b;

	tmp_a = lista->first;
	tmp_b = listb->first;
	if (lista == NULL || listb == NULL)
		return (1);
	len_a = ft_lstsize(lista->first);
	len_b = 0;
	if (listb->first == NULL)
	{
		printf("Liste B est NULL\n");
		len_b = 0;
	}
	else
	{
		printf("liste B est different de nul\n");
		len_b = ft_lstsize(listb->first);
	}
	if (listb->first == NULL)
	{
		while (tmp_a != NULL)
		{
			printf("c1\t%d  \n", tmp_a->number);
			tmp_a = tmp_a->next;
		}
	}
	else if (len_a >= len_b)
	{
		printf("len_a=%d >= len_b=%d\n", len_a, len_b);
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
	else if (len_b > len_a)
	{
		printf("len_b=%d > len_a=%d\n", len_b, len_a);
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
	printf("  \t_ _\n");
	printf("  \ta b\n");
	return (0);
}

void			ft_display_info(int nbr, t_data *lst_a, t_data *lst_b)
{
	printf("SOLVE TEST <100\n");
	printf("Q1 = %d\n", lst_a->q_one);
	printf("Mediane = %d\n", lst_a->median);
	printf("Q3 = %d \n", lst_a->q_three);
	printf("Nombre de chiffres: %d\n", nbr);
	printf("Emplacement du plus petit: %d\n", ft_find_small(lst_a));
	printf("Emplacement du plus grand: %d\n", ft_find_big(lst_a));
	printf("Taille de la liste : %d\n", ft_len_list(lst_a));
	printf("Nombre des actions totales: %d\n", lst_a->total + lst_b->total);
	printf("nbr = %d nbr mod 2 = %d\n", nbr, nbr % 2);
	sleep(5);
	ft_display_lst(lst_a, lst_b);
	sleep(2);
}
