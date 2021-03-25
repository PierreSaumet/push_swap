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

#include "../../headers/checker.h"


int     ft_pb(t_data *lst_a, t_data *lst_b)
{
    // met le premier elemnt de A dans B
    t_list *tmp_a;
    t_list *tmp_b;
    printf("Dans PB...\n");
    if (lst_a == NULL || lst_b == NULL)
        exit(EXIT_FAILURE);
    if (lst_a->first == NULL)
    {
        printf("le premier de A est null\n");
        return (0);
        printf("ERROR\n");
        return(1);
        //exit(EXIT_FAILURE);
    }
    tmp_a = lst_a->first;
    // on malloc le nouvel elem de lst_b
    if (!(tmp_b = malloc(sizeof(t_list))))
        exit(EXIT_FAILURE);
    tmp_b->number = tmp_a->number;
    tmp_b->next = lst_b->first;

    // rajout liste doublement chained
    tmp_b->prev = NULL;
    if (lst_b->first)
            lst_b->first->prev = tmp_b;
        else
            lst_b->last = tmp_b;
    // fin liste doublement chained
    lst_b->first = tmp_b;
    printf("On a copier donc lst_b = %d\n", lst_b->first->number);

    // on supprime le premier element de lst a
    lst_a->first = lst_a->first->next;
    if (lst_a->first != NULL)
        lst_a->first->prev = NULL;
    free(tmp_a);

    // affichage test double chained
    if (lst_a->first != NULL)
    {
        printf("\n\nFIN DE PB\n\n");
        printf("lst_a->first->number = %d\n", lst_a->first->number);
        printf("lst_a->last->number = %d\n", lst_a->last->number);
        printf("lst_b->first->number = %d\n", lst_b->first->number);
        printf("lst_b->last->number = %d\n", lst_b->last->number);
    }
    else
    {
        lst_a->first = NULL;
        lst_a->last = NULL;
        printf("lst_a->first = %p\n", lst_a->first);
        printf("lst_a->last = %p\n", lst_a->last);
    }
    return (0);
}

int     ft_pa(t_data *lst_a, t_data *lst_b)
{
    // met le premier elemnt de B dans A
    t_list *tmp_a;
    t_list *tmp_b;
    printf("Dans PA...\n");
    if (lst_a == NULL || lst_b == NULL)
        exit(EXIT_FAILURE);
    if (lst_b->first == NULL)
    {
        printf("le premier de B est null\n");
        return (0);
        printf("ERROR\n");
        return(1);
        //exit(EXIT_FAILURE);
    }
    tmp_b = lst_b->first;
    // on malloc le nouvel elem de lst_a
    if (!(tmp_a = malloc(sizeof(t_list))))
        exit(EXIT_FAILURE);
    tmp_a->number = tmp_b->number;
    tmp_a->next = lst_a->first;

    // rajout liste doublement chained
    tmp_a->prev = NULL;
    if (lst_a->first)
            lst_a->first->prev = tmp_a;
        else
            lst_a->last = tmp_a;
    // fin liste doublement chained
    lst_a->first = tmp_a;
    printf("On a copier donc lst_a = %d\n", lst_a->first->number);

    // on supprime le premier element de lst b
    lst_b->first = lst_b->first->next;
    if (lst_b->first != NULL)
        lst_b->first->prev = NULL;
    free(tmp_b);

    // affichage test double chained
    if (lst_b->first != NULL)
    {
        printf("\n\nFIN DE PA\n\n");
        printf("lst_a->first->number = %d\n", lst_a->first->number);
        printf("lst_a->last->number = %d\n", lst_a->last->number);
        printf("lst_b->first->number = %d\n", lst_b->first->number);
        printf("lst_b->last->number = %d\n", lst_b->last->number);
    }
    else
    {
        lst_b->first = NULL;
        lst_b->last = NULL;
        printf("lst_b->first = %p\n", lst_b->first);
        printf("lst_b->last = %p\n", lst_b->last);
    }
    return (0);
}