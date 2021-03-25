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

#include "../../headers/checker.h"


int     ft_ra(t_data *lst_a)
{
    // tourne les elements de A
    t_list *tmp_a;
    int     tmp_nbr;
    printf("Dans RA...\n");
    if (lst_a == NULL)
        exit(EXIT_FAILURE);
    if (ft_lstsize(lst_a->first) <= 1)
    {
        printf("la liste A contient 1 ou 0 elem\n");
        return (0);
    }
    tmp_a = lst_a->first;
    tmp_nbr = tmp_a->number;

    printf("ICI\n");
    printf("tmp_a->number = %d\n", tmp_a->number);
    printf("tmp_a->next->number = %d\n", tmp_a->next->number);
    printf("tmp_a->prev->number = %p\n", tmp_a->prev);
    while (tmp_a->next != NULL)
    {
        tmp_a->number = tmp_a->next->number;
        tmp_a = tmp_a->next;
        printf("LA\n");
        printf("tmp_a->number = %d\n", tmp_a->number);
        if ((tmp_a->next != NULL))
            printf("tmp_a->next->number = %d\n", tmp_a->next->number);
        printf("tmp_a->prev->number = %d\n", tmp_a->prev->number);
    }
    tmp_a->number = tmp_nbr;

    printf("END\n");
    printf("tmp_a->number = %d\n", tmp_a->number);
    printf("tmp_a->next->number = %p\n", tmp_a->next);
    printf("tmp_a->prev->number = %d\n", tmp_a->prev->number);

    // affichage test double chained
    if (lst_a->first != NULL)
    {
        printf("\n\nFIN DE RA\n\n");
        printf("lst_a->first->number = %d\n", lst_a->first->number);
        printf("lst_a->last->number = %d\n", lst_a->last->number);
    
    }

    return (0);
}

int     ft_rb(t_data *lst_b)
{
    // tourne les elements de B
    t_list *tmp_b;
    int     tmp_nbr;
    printf("Dans Rb...\n");
    if (lst_b == NULL)
        exit(EXIT_FAILURE);
    if (ft_lstsize(lst_b->first) <= 1)
    {
        printf("la liste A contient 1 ou 0 elem\n");
        return (0);
    }
    tmp_b = lst_b->first;
    tmp_nbr = tmp_b->number;

    printf("ICI\n");
    printf("tmp_b->number = %d\n", tmp_b->number);
    printf("tmp_b->next->number = %d\n", tmp_b->next->number);
    printf("tmp_b->prev->number = %p\n", tmp_b->prev);
    while (tmp_b->next != NULL)
    {
        tmp_b->number = tmp_b->next->number;
        tmp_b = tmp_b->next;
        printf("LA\n");
        printf("tmp_b->number = %d\n", tmp_b->number);
        if ((tmp_b->next != NULL))
            printf("tmp_b->next->number = %d\n", tmp_b->next->number);
        printf("tmp_b->prev->number = %d\n", tmp_b->prev->number);
    }
    tmp_b->number = tmp_nbr;

    printf("END\n");
    printf("tmp_b->number = %d\n", tmp_b->number);
    printf("tmp_b->next->number = %p\n", tmp_b->next);
    printf("tmp_b->prev->number = %d\n", tmp_b->prev->number);

    // affichage test double chained
    if (lst_b->first != NULL)
    {
        printf("\n\nFIN DE RB\n\n");
        printf("lst_b->first->number = %d\n", lst_b->first->number);
        printf("lst_b->last->number = %d\n", lst_b->last->number);
    
    }
    return (0);
}