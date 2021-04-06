/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"


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
		sleep(1);
		//sleep(2);
		//printf("FIN number = %d\n", tmp->number);
		//ft_display_lst(lst_a, lst_b);
		//sleep(3);
		
	}
	printf("end = %d\n\n\n\n", end);
	tmp = lst_a->first;
	int count;
	count = 0;

    t_list *tmp2 = lst_b->first;

    ft_display_lst(lst_a, lst_b);
    while (ft_find_small(lst_b) != 1)
    {
        ft_rb(lst_b);
	    write(1, "rb\n", 3);
		count++;
    }
    printf("le plus petit = %d et le plus grand = %d\n", ft_find_small(lst_b), ft_find_big(lst_b));
    printf("fin de ROTATE\n");
    ft_display_lst(lst_a, lst_b);
	
    
    while (1)
	{
		printf("number = %d et next = %d\n", tmp->number, tmp->next->number);
		printf("trie ?? %d\n", ft_end2(lst_a, lst_b));
		sleep(2);
		if (ft_end2(lst_a, lst_b) == 0)
		{
			break;
		}
        /////////////////////////////////////////////////
        // Test avec la deuxieme liste
        /////////////////////////////////////////////////
        // while (ft_find_small(lst_b) != 1)
        // {
        //     ft_rb(lst_b);
		// 	write(1, "rb\n", 3);
		// 	count++;
        // }
        // printf("le plus petit = %d et le plus grand = %d\n", ft_find_small(lst_b), ft_find_big(lst_b));
        // printf("fin de ROTATE\n");
        // ft_display_lst(lst_a, lst_b);

        sleep(2);
        
        printf("\n\nDEBUT lst_b = %d\n", tmp2->number);
        ft_display_lst(lst_a, lst_b);
        if (tmp2->number < tmp2->next->number)
        {
            ft_rb(lst_b);
            write(1, "rb\n", 3);
            count++;
        }
        else if (tmp2->number > tmp2->next->number)
        {
            ft_sb(lst_b);
			write(1, "sb\n", 3);
			count++;
            tmp2 = lst_b->first;
            if (tmp2->number < lst_b->last->number)
            {
                ft_rrb(lst_b);
                write(1, "rrb\n", 4);
                count++;
                tmp2 = lst_b->first;
            }
        }
        tmp2 = lst_b->first;
        printf("fin\n");
        ft_display_lst(lst_a, lst_b);
        sleep(3);
        








        /*
        // test mettre le plus petit en debut de liste
        printf("le plus petit = %d et le plus grand = %d\n", ft_find_small(lst_a), ft_find_big(lst_a));
        while (ft_find_small(lst_a) != 1)
        {
            ft_ra(lst_a);
			write(1, "ra\n", 3);
			count++;
        }
        printf("le plus petit = %d et le plus grand = %d\n", ft_find_small(lst_a), ft_find_big(lst_a));
        printf("fin de ROTATE\n");
        ft_display_lst(lst_a, lst_b);
        sleep(5);

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
        */
	}
	printf("c'est trie et action = %d\n", count);
	return (0);
}








