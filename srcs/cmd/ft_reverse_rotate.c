/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

int     ft_rra(t_data *lst_a)
{
	printf("Dans RRA...\n");
	t_list *tmp_a;
	int     tmp_nbr;
	if (lst_a == NULL)
		exit(EXIT_FAILURE);
	if (ft_lstsize(lst_a->first) <= 1)
	{
		printf("la liste A contient 1 ou 0 elem\n");
		return (0);
	}
	tmp_a = lst_a->last;
	tmp_nbr = tmp_a->number;
	(void)tmp_nbr;
	printf("ICI\n");
	printf("tmp_a->number = %d\n", tmp_a->number);
	printf("tmp_a->next->number = %p\n", tmp_a->next);
	printf("tmp_a->prev->number = %d\n", tmp_a->prev->number);

	while (tmp_a->prev != NULL)
	{
		tmp_a->number = tmp_a->prev->number;
		tmp_a = tmp_a->prev;
		printf("LA\n");
		printf("tmp_a->number = %d\n", tmp_a->number);
		if ((tmp_a->prev != NULL))
			printf("tmp_a->prev->number = %d\n", tmp_a->prev->number);
		printf("tmp_a->next->number = %d\n", tmp_a->next->number);
	}
	tmp_a->number = tmp_nbr;
	 printf("END\n");
	printf("tmp_a->number = %d\n", tmp_a->number);
	printf("tmp_a->next->number = %d\n", tmp_a->next->number);
	printf("tmp_a->prev = %p\n", tmp_a->prev);

	// affichage test double chained
	if (lst_a->first != NULL)
	{
		printf("\n\nFIN DE RRA\n\n");
		printf("lst_a->first->number = %d\n", lst_a->first->number);
		printf("lst_a->last->number = %d\n", lst_a->last->number);
	
	}
	return (0);
}


int     ft_rrb(t_data *lst_b)
{
	printf("Dans RRB...\n");
	t_list *tmp_b;
	int     tmp_nbr;
	if (lst_b == NULL)
		exit(EXIT_FAILURE);
	if (ft_lstsize(lst_b->first) <= 1)
	{
		printf("la liste A contient 1 ou 0 elem\n");
		return (0);
	}
	tmp_b = lst_b->last;
	tmp_nbr = tmp_b->number;
	(void)tmp_nbr;
	printf("ICI\n");
	printf("tmp_b->number = %d\n", tmp_b->number);
	printf("tmp_b->next->number = %p\n", tmp_b->next);
	printf("tmp_b->prev->number = %d\n", tmp_b->prev->number);

	while (tmp_b->prev != NULL)
	{
		tmp_b->number = tmp_b->prev->number;
		tmp_b = tmp_b->prev;
		printf("LA\n");
		printf("tmp_b->number = %d\n", tmp_b->number);
		if ((tmp_b->prev != NULL))
			printf("tmp_b->prev->number = %d\n", tmp_b->prev->number);
		printf("tmp_b->next->number = %d\n", tmp_b->next->number);
	}
	tmp_b->number = tmp_nbr;
	printf("END\n");
	printf("tmp_b->number = %d\n", tmp_b->number);
	printf("tmp_b->next->number = %d\n", tmp_b->next->number);
	printf("tmp_b->prev = %p\n", tmp_b->prev);

	// affichage test double chained
	if (lst_b->first != NULL)
	{
		printf("\n\nFIN DE RRB\n\n");
		printf("lst_b->first->number = %d\n", lst_b->first->number);
		printf("lst_b->last->number = %d\n", lst_b->last->number);
	
	}
	return (0);
}
