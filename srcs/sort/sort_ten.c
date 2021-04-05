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
	{
		ft_do(nbr, lst_a, lst_b);

	}
	else if (ft_find_small(lst_a) == 4)
	{
		ft_rra(lst_a);
		write(1, "rra\n", 4);
		if (ft_end(lst_a, lst_b) == 1)
		{
			ft_do(nbr, lst_a, lst_b);
		}
	}
	else if (ft_find_small(lst_a) == 3)
	{
		ft_rra(lst_a);
		write(1, "rra\n", 4);
		ft_rra(lst_a);
		write(1, "rra\n", 4);	
		if (ft_end(lst_a, lst_b) == 1)
		{
			ft_do(nbr, lst_a, lst_b);
		}
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
				//printf("tmp_1 = %d \t tmp_2 = %d\n", tmp_1->number, tmp_2->number);

				if (tmp_1->number > tmp_2-> number)
					inf++;
				else if (tmp_1->number < tmp_2->number)
					sup++;
				tmp_2 = tmp_2->next;
			}
			//printf("le nombre %d, inf = %d et sup = %d\n", tmp_1->number, inf, sup);
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
		printf("mediane nbr / 2 = %d\n", (nbr/2));
		sleep(5);
		return (nbr / 2);
	}


	return (-1);
}


int			solve_5(int nbr, t_data *lst_a, t_data *lst_b)
{
	printf("nbr moulo 2 = %d et nbr / 2 = %d\n", (nbr % 2),  (nbr / 2));
	
	// trouver la mediane
	int mediane;

	mediane = find_mediane(nbr, lst_a);
	printf("mediane = %d\n", mediane);

	t_list *tmp;
	tmp = lst_a->first;

	//sleep(2);
	printf("\n\n\n\n DEBUT DU TRI...\n");
	int end = 0;
	while (tmp && end < 2)
	{
		//printf("\n\n");
		//ft_display_lst(lst_a, lst_b);


		sleep(2);
		printf("number = %d et medinae %d\n", tmp->number, mediane);
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
		

		//printf("FIN number = %d\n", tmp->number);
		//ft_display_lst(lst_a, lst_b);
		//sleep(3);
		
	}
	printf("end = %d\n", end);

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
		
	printf("\n\nFIN DU TRI\n");
	ft_display_lst(lst_a, lst_b);
	//(void)lst_b;
	
	
	return (0);
}

int			partitionner(int *tableau, int p, int r)
{
	int pivot;
	int i;
	int j;
	int temp;

	pivot = tableau[p];
	i = p - 1;
	j = r + 1;
	while (1)
	{
		do
			j--;
		while (tableau[j] > pivot);
		do
			i++;
		while (tableau[i] < pivot);
			if (i < j)
			{
				temp = tableau[i];
				tableau[i] = tableau[j];
				tableau[j] = temp;
			}
			else
				return j;		
	}
}

void		quicksort(int *tableau, int p, int r)
{
	int q;

	if (p < r)
	{
		q = partitionner(tableau, p, r);
		quicksort(tableau, p, q);
		quicksort(tableau, q+1, r);
	}
}


// verifie que la liste est trie du + grand au plus petit
int         ft_end2(t_data *lst_a, t_data *lst_b)
{
	t_list  *tmp_a;

	tmp_a = lst_a->first;
	(void)lst_b;
	while (tmp_a->next != NULL)
	{
		if (tmp_a->number < tmp_a->next->number)
			return (1);
		tmp_a = tmp_a->next;
	}
	return (0);

}
int			other(int nbr, t_data *lst_a, t_data *lst_b)
{
	printf("dans other nbr = %d\n", nbr);
	printf("nbr modulo 2 = %d et nbr / 2 = %d\n", (nbr % 2),  (nbr / 2));
	
	// trouver la mediane
	int mediane;

	mediane = find_mediane(nbr, lst_a);
	printf("mediane = %d\n", mediane);

	t_list *tmp;
	tmp = lst_a->first;

	//sleep(2);
	printf("\n\n\n\n DEBUT DU TRI...\n");
	int end = 0;

	// a rajouter une condition pour cas pair et impair
	while (tmp && end < (mediane - 1))
	{
		//printf("\n\n");
		//ft_display_lst(lst_a, lst_b);



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
		printf("end = %d et medianne = %d\n", end, mediane);
		sleep(5);
		//sleep(2);
		//printf("FIN number = %d\n", tmp->number);
		//ft_display_lst(lst_a, lst_b);
		//sleep(3);
		
	}
	printf("end = %d\n\n\n\n", end);
	tmp = lst_a->first;
	int count;
	count = 0;
	while (1)
	{
		printf("number = %d et next = %d\n", tmp->number, tmp->next->number);
		printf("trie ?? %d\n", ft_end2(lst_a, lst_b));
		sleep(2);
		if (ft_end2(lst_a, lst_b) == 0)
		{
			break;
		}
		if (tmp->number > tmp->next->number) // le plus petit devient premier
		{
			ft_sa(lst_a);
			write(1, "sa\n", 3);
			count++;
		}
		else
		{
			ft_ra(lst_a);
			write(1, "ra\n", 3);
			count++;
		}
		tmp = lst_a->first;
		ft_display_lst(lst_a, lst_b);
		sleep(5);
	}
	printf("c'est trie et action = %d\n", count);
	return (0);
}










int         nbr_ten(int nbr, t_data *lst_a, t_data *lst_b)
{
	printf("dans 10\n");

	if (nbr == 4)
	{
		solve_4(nbr, lst_a, lst_b);
	}
	else if (nbr == 5)
	{
		solve_5(nbr, lst_a, lst_b);
	}
	else
	{
		other(nbr, lst_a, lst_b);
	}

	return (0);
}