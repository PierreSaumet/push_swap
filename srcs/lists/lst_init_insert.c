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

#include "../../headers/checker.h"

void        ft_insertion(t_data *listA, int nbr)
{
    t_list *new;

    if (!(new = malloc(sizeof(t_list))))
        return ;
    new->number = nbr;
    new->next = listA->first;
    listA->first = new;
}

int         ft_full_insertion(t_data *listA, int argc, char **argv)
{
    argc = argc - 1;
    while (argc > 1)
    {
        t_list *new;

        if (!(new = malloc(sizeof(t_list))))
            return (1);
        new->number = atoi(argv[argc - 1]);
        printf("new->number = %d\n", new->number);
        new->next = listA->first;
        new->prev = NULL;
        if (listA->first)
            listA->first->prev = new;
        else
            listA->last = new;
        listA->first = new;
        argc--;
    }
    return (0);
}

t_data      *initialize_list(int argc, char **argv)
{
    t_data *list;
    t_list  *element;

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