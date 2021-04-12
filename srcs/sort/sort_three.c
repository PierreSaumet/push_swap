/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

/*
**  This file contains 5 functions:
**  -'int         ft_find_small(t_data *lst)':  finds the emplacement of the
**  smallest number of the stack.
**  -'int         ft_find_big(t_data *lst)':    finds the emplacement of the
**  biggesy number of the stack.
**  -'int         solve_2(t_data *lst_a)':  resolve if there are 2 numbers.
**  -'int         solve_3(t_data *lst_a)':  resolve if there are 3 numbers.
**  -'int         nbr_three(int nbr, t_data *lst_a, t_data *lst_b)':
**      choose between the 2 functions above.
*/
int         ft_find_small(t_data *lst)
{
    t_list  *tmp;
    int     emp;
    int     min;

    if (lst == NULL)
		exit(EXIT_FAILURE);
    tmp = lst->first;
    emp = 1;
    min = tmp->number;
    while (tmp->next != NULL)
    {
        if (min > tmp->next->number)
            min = tmp->next->number;
        tmp = tmp->next;
    }
    tmp = lst->first;
    while (tmp->number != min)
    {
        emp++;
        tmp = tmp->next;
    }
    return (emp);
}

int         ft_find_big(t_data *lst)
{
    t_list  *tmp;
    int     emp;
    int     max;

    if (lst == NULL)
		exit(EXIT_FAILURE);
    tmp = lst->first;
    emp = 1;
    max = tmp->number;
    while (tmp->next != NULL)
    {
        if (max < tmp->next->number)
            max = tmp->next->number;
        tmp = tmp->next;
    }
    tmp = lst->first;
    while (tmp->number != max)
    {
        emp++;
        tmp = tmp->next;
    }
    return (emp);
}

int         solve_2(t_data *lst_a)
{
    if (lst_a->first->number > lst_a->first->next->number)
        ft_sa(lst_a);
    write(1, "sa\n", 3);
    return (0);
}

int         solve_3(t_data *lst_a)
{
    if (ft_find_big(lst_a) == 2)
    {
        ft_rra(lst_a);
        write(1, "rra\n", 4);
        if (ft_find_small(lst_a) == 2)
        {
            ft_sa(lst_a);
            write(1, "sa\n", 3);
        }
    }
    if (ft_find_big(lst_a) == 1)
    {
        ft_ra(lst_a);
        write(1, "ra\n", 3);
        if (ft_find_small(lst_a) == 2)
        {
            ft_sa(lst_a);
            write(1, "sa\n", 3);
        }
    }
    return (0);
}

int         nbr_three(int nbr, t_data *lst_a, t_data *lst_b)
{
    if (nbr == 2)
        return (solve_2(lst_a));
    else if (nbr == 3)
    {
        if (ft_find_big(lst_a) == 3)
        {
            ft_sa(lst_a);
            write(1, "sa\n", 3);
        }
        else
            return (solve_3(lst_a));
    }
    else
        return (1);
    (void)lst_b;
    return (0);
}