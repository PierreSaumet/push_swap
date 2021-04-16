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
**  This file contains 1 function:
**  -'int   ft_len_list(t_data *lst)':              return the length of the
**   chained list.
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
