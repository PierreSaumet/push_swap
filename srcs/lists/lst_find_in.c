/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**  This file contains 4 functions:
**  -'int   ft_len_list(t_data *lst)':              return the length of the
**   chained list.
**  -'int   ft_get_small(int med, t_data *lst)':    find the smallest number
**  under the median.
**  -'int   ft_get_big(int med, t_data *lst)':      find the biggest number
**  under the median.
**  -'int   ft_find_big_med(int med, t_data *lst)': find the location of the
**  biggest number under the median.
*/

int				ft_len_list(t_data *lst)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = lst->first;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int				ft_get_small(int med, t_data *lst)
{
	t_list		*tmp;
	int			min;

	if (lst == NULL)
	{
		printf("Dans ft_get_small, liste donnee = NULL\n");
		exit(EXIT_FAILURE);
	}
	tmp = lst->first;
	min = 2147483647;
	while (tmp != NULL)
	{
		if (min > tmp->number && tmp->number < med)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min);
}

int				ft_get_big(int med, t_data *lst)
{
	t_list		*tmp;
	int			max;

	if (lst == NULL)
	{
		printf("Dans ft_get_big, liste donnee = NULL\n");
		exit(EXIT_FAILURE);
	}
	tmp = lst->first;
	max = -2147483648;
	while (tmp != NULL)
	{
		if (max < tmp->number && tmp->number < med)
			max = tmp->number;
		tmp = tmp->next;
	}
	return (max);
}

int				ft_find_big_med(int med, t_data *lst)
{
	t_list		*tmp;
	int			emp;
	int			max;

	if (lst == NULL)
		exit(EXIT_FAILURE);
	tmp = lst->first;
	emp = 1;
	max = -2147483648;
	while (tmp != NULL)
	{
		if (max < tmp->number && tmp->number <= med)
			max = tmp->number;
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
