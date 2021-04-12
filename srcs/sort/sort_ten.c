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

static int			ft_do(int nbr, t_data *lst_a, t_data *lst_b)
{
	ft_pb(lst_a, lst_b);
	write(1, "pb\n", 3);
	nbr_three(nbr - 1, lst_a, lst_b);
	ft_pa(lst_a, lst_b);
	write(1, "pa\n", 3);
	return (0);
}

int			solve_4(int nbr, t_data *lst_a, t_data *lst_b)
{
	if (ft_find_small(lst_a) == 1)
		ft_do(nbr, lst_a, lst_b);
	else if (ft_find_small(lst_a) == 4)
	{
		ft_rra(lst_a);
		write(1, "rra\n", 4);
		if (ft_end(lst_a, lst_b) == 1)
			ft_do(nbr, lst_a, lst_b);
	}
	else if (ft_find_small(lst_a) == 3)
	{
		ft_rra(lst_a);
		write(1, "rra\n", 4);
		ft_rra(lst_a);
		write(1, "rra\n", 4);	
		if (ft_end(lst_a, lst_b) == 1)
			ft_do(nbr, lst_a, lst_b);
	}
	else if (ft_find_small(lst_a) == 2)
	{
		ft_ra(lst_a);
		write(1, "ra\n", 3);
		if (ft_end(lst_a, lst_b) == 1)
			ft_do(nbr, lst_a, lst_b);
	}
	return (0);
}


int			find_mediane(int nbr, t_data *lst_a)
{

	t_list	*tmp_1;
	t_list	*tmp_2;

	tmp_1 = lst_a->first;
	tmp_2 = tmp_1->next;


	int sup = 0;
	int inf = 0;

	if ((nbr % 2) == 1)	// LISTE IMPAIRE 5 ou 9
	{
		printf("Oui, impair\n");
		while (tmp_1)
		{
			inf = 0;
			sup = 0;
			tmp_2 = lst_a->first;
			while (tmp_2)
			{
				if (tmp_1->number > tmp_2-> number)
					inf++;
				else if (tmp_1->number < tmp_2->number)
					sup++;
				tmp_2 = tmp_2->next;
			}
			if (inf == sup)
			{
				printf("la mediane est =%d car inf = %d et sup = %d\n", tmp_1->number, inf, sup);
				return (tmp_1->number);
			}
			tmp_1 = tmp_1->next;
		}
	}
	else
	{
		return (nbr / 2);
	}
	return (-1);
}


int			solve_5(int nbr, t_data *lst_a, t_data *lst_b)
{
    // printf("Dans solve_5\n");
	int mediane;

	mediane = find_mediane(nbr, lst_a);

	t_list *tmp;
	tmp = lst_a->first;

	int end = 0;
	while (tmp && end < 2)
	{
		if (tmp->number < mediane)
		{
			ft_pb(lst_a, lst_b);
			write(1, "pb\n", 3);
			end++;
		}
		else
		{
			ft_ra(lst_a);
			write(1, "ra\n", 3);
		}
		tmp = lst_a->first;
		
	}
	solve_3(lst_a);
	if (lst_b->first->number < lst_b->last->number)
	{
		ft_sb(lst_b);
		write(1, "sb\n", 3);
	}
	ft_pa(lst_a, lst_b);
	write(1, "pa\n", 3);
	ft_pa(lst_a, lst_b);
	write(1, "pa\n", 3);
	return (0);
}


int         nbr_ten(int nbr, t_data *lst_a, t_data *lst_b)
{
	if (nbr == 4)
		solve_4(nbr, lst_a, lst_b);
	else if (nbr == 5)
		solve_5(nbr, lst_a, lst_b);
	else if (nbr <= 100)
	{
		other(nbr, lst_a, lst_b);
	}
    else if (nbr <= 2000)
    {
        sort_2000(nbr, lst_a, lst_b);
    }

	return (0);
}