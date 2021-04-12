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
**	Trie le tableau pour avoir les quartiles et la mediane
*/
void		sort_array(long *array, int nbr)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < nbr - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

/*
**	Trouve la mediane et les quartiles
*/
int			ft_find_mediane(int nbr, t_data *lst)
{
	t_list *tmp;
	long	*array;
	int		i;
	int		q;

	tmp = lst->first;
	i = 0;
	q = nbr / 4;
	if (!(array = (long *)malloc(sizeof(long) * (nbr + 1))))
		exit(EXIT_FAILURE);
	while (i < nbr)
	{
		array[i++] = tmp->number;
		tmp = tmp->next;
	}
	sort_array(array, nbr);
	lst->q_one = array[q];
	lst->median = array[q * 2];
	lst->q_three = array[q * 3];
	free(array);
	return (0);
}

int			push_first_quartile(int nbr, t_data *lst_a, t_data *lst_b)
{
	int		end;
	int		count;
	t_list	*tmp_a;

	end = 0;
\
	tmp_a = lst_a->first;
	count = 0;
    (void)count;
    //printf("nbr mod 4 = %d\n", nbr % 4);
    //sleep(100);

    while (tmp_a != NULL)
    {
        if (tmp_a->number <= lst_a->q_one)
		{
            end++;
        }
        tmp_a = tmp_a->next;
    }

    //sleep(10);
    tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number <= lst_a->q_one)
		{
			if (lst_b->first && lst_b->first->number > lst_a->q_one / 2)
			{
				ft_do_rb(lst_b);
			}
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);


		tmp_a = lst_a->first;
	}

    // printf("STOP\n");
    // sleep(10);
    (void)nbr;
;	return (0);
}

int				push_second_quartile(int nbr, t_data *lst_a, t_data *lst_b)
{
	int		end;
	int		count;
	t_list	*tmp_a;

	end = 0;
	tmp_a = lst_a->first;
	count = 0;
    // printf("DEBUTsecond quartile\n");
    // sleep(5);
    printf(" TEST 2...\n");
    sleep(1);
    (void)nbr;
    while (tmp_a != NULL)
    {
        if (tmp_a->number > lst_a->q_one && tmp_a->number <= lst_a->median)
		{
            end++;
        }
        tmp_a = tmp_a->next;
    }
    //ft_display_lst(lst_a, lst_b);
    // printf("finb de test end = %d\n", end);
    // sleep(5);
    (void)count;
	tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number > lst_a->q_one && tmp_a->number <= lst_a->median)
		{
			if (lst_b->first && lst_b->first->number > (lst_a->median / 4) * 3)
			{
				ft_do_rb(lst_b);
			}
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		//printf("count = %d\n et nbr / 4 = %d\n", count, nbr / 4);
		// if (nbr % 4 == 1)
        // {
        //     if (count == (nbr / 4) + 1)
        //     {
        //        	end = 1;
		//      	ft_display_lst(lst_a, lst_b);
		//         printf("FIN de push quartile avec Q2 = %d  MODULO\n", lst_a->q_one);
		//         sleep(5);
        //     }
        // }
        // else
        // {
        //     if (count == nbr / 4)
		//     {
		// 	    end = 1;
		// 	    ft_display_lst(lst_a, lst_b);
		// 	    printf("FIN de push quartile avec Q2 = %d\n", lst_a->q_one);
		// 	    sleep(5);
		//     }
        // }
		tmp_a = lst_a->first;
        // ft_display_lst(lst_a, lst_b);
        // sleep(1);

	}
	return (0);
}

int				push_third_quartile(int nbr, t_data *lst_a, t_data *lst_b)
{
	int		end;
	int		count;
	t_list	*tmp_a;

	end = 0;
	tmp_a = lst_a->first;
	count = 0;
    (void)count;
    (void)nbr;

    while (tmp_a != NULL)
    {
        if (tmp_a->number > lst_a->median && tmp_a->number <= lst_a->q_three)
		{
            end++;
        }
        tmp_a = tmp_a->next;
    }
    tmp_a = lst_a->first;
	while (end > 0)
	{
		if (tmp_a->number > lst_a->median && tmp_a->number <= lst_a->q_three)
		{
			if (lst_b->first && lst_b->first->number > (lst_a->median / 4) * 7)
			{
				ft_do_rb(lst_b);
			}
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		// ft_display_lst(lst_a, lst_b);
		// printf("count = %d\n et nbr / 4 = %d\n", count, nbr / 4);
		// printf("q_three = %d\n", lst_a->q_three);
		// if (count == nbr / 4)
		// 	end = 0;
		tmp_a = lst_a->first;
	}
	return (0);
}

int				push_last_quartile(int nbr, t_data *lst_a, t_data *lst_b)
{
	int		end;
	int		count;
	t_list	*tmp_a;

	end = 0;
	tmp_a = lst_a->first;
	count = 0;
    (void)nbr;
    (void)count;

    while (tmp_a != NULL)
    {
        if (tmp_a->number > lst_a->q_three)
		{
            end++;
        }
        tmp_a = tmp_a->next;
    }
    tmp_a = lst_a->first;
    //printf("end = %d\n", end);
    //sleep(50);
	while (end > 0)
	{
		if (tmp_a->number > lst_a->q_three)
		{
			if (lst_b->first && lst_b->first->number > (lst_a->median / 4) * 5)
			{
				ft_do_rb(lst_b);
			}
			ft_do_pb(lst_a, lst_b);
			end--;
		}
		else
			ft_do_ra(lst_a);
		// printf("count = %d\n et nbr / 4 = %d\n", count, nbr / 4);
		// if (count == nbr / 4)
		// 	end = 0;
		tmp_a = lst_a->first;
	}
	return (0);
}

int             ft_do_pa(t_data *lst_a, t_data *lst_b)
{
    ft_pa(lst_a, lst_b);
	write(1, "pa\n", 3);
    lst_a->total++;
    return (0);
}

// int             ft_do_ra(t_data *lst)
// {
//     ft_ra(lst);
// 	write(1, "ra\n", 3);
// 	lst->total++;
//     return (0);
// }

int				ft_find_best2(int nbr, t_data *lst, int div)
{
    printf("Dans find_best 2\n");
	int			diff_min;
	int			diff_max;

	if (lst == NULL)
		return (1);
	diff_min = ft_len_list(lst) - ft_find_small(lst);
	diff_max = ft_len_list(lst) - ft_find_big(lst);
	if (ft_len_list(lst) == 1)
		return (-1);

    

	if (ft_find_small(lst) < (ft_len_list(lst) / 2) && ft_find_big(lst) < (ft_len_list(lst) / 2))
	{
        ft_do_rb(lst);
    }
	else if (ft_find_small(lst) > (ft_len_list(lst) / 2) && ft_find_big(lst) > (ft_len_list(lst) / 2))
	{
        ft_do_rrb(lst);
    }
	else
    {
        // printf("LA\n");
        // printf("len de B = %d et la moitie = %d\n", ft_len_list(lst), ft_len_list(lst) / 2);
        // printf("petit = %d et grand = %d\n", ft_find_small(lst), ft_find_big(lst));
        
        // printf("diffmin = %d et diffmax = %d\n", diff_min, diff_max);
        // printf("gros test...");

        if (ft_find_small(lst) > (ft_len_list(lst) / 2))
            diff_min = ft_len_list(lst) - ft_find_small(lst);
        else
            diff_min = ft_find_small(lst);
        if (ft_find_big(lst) > (ft_len_list(lst) / 2))
            diff_max = ft_len_list(lst) - ft_find_big(lst);
        else
            diff_max = ft_find_big(lst);





        if (diff_max < diff_min)
        {
            if (ft_find_big(lst) <= (ft_len_list(lst) / 2))
            {
                while (ft_find_big(lst) != 1)
                {
                    // printf("la?\n");
                    // sleep(1);
                    ft_do_rb(lst);
                }
            }
            else
            {
                while (ft_find_big(lst) != 1)
                    ft_do_rrb(lst);
            }
        }
        else
        {
            if (ft_find_small(lst) <= (ft_len_list(lst) / 2))
            {
                while (ft_find_small(lst) != 1)
                {
                    // printf("ici?\n");
                    // sleep(1);
                    ft_do_rb(lst);
                }
            }
            else
            {
                while (ft_find_small(lst) != 1)
                    ft_do_rrb(lst);
            }
        }
        //sleep(2);
        
        //ft_end_find_best(diff_min, diff_max, lst, div);
    }
    (void)diff_max;
    (void)diff_min;
    (void)nbr;
    (void)div;
	return (0);
}



int			sort_b_to_a(int nbr, t_data *lst_a, t_data *lst_b, int div)
{
	t_list	*tmp_b;

	tmp_b = lst_b->first;
	while (tmp_b != NULL)
	{
		//printf("Le plus petit de B = %d\n", ft_find_small(lst_b));
		//printf("Le plus grand de B = %d\n", ft_find_big(lst_b));
		if (ft_find_small(lst_b) == 1)
		{
			ft_do_pa(lst_a, lst_b);
			ft_do_ra(lst_a);

		}
		else if (ft_find_big(lst_b) == 1)
		{
			ft_do_pa(lst_a, lst_b);
            lst_a->count_ra++;
		}
        else
        {
		    if (ft_find_best2(nbr, lst_b, div) == -1)
		    {
		    	ft_do_pa(lst_a, lst_b);
		    }
        }
		tmp_b = lst_b->first;
		//sleep(10);
	}
	(void)div;
	(void)tmp_b;
	(void)nbr;
	(void)lst_a;
	(void)lst_b;
	return (0);
}

int         sort_2000(int nbr, t_data *lst_a, t_data *lst_b)
{
	printf("DANS sort_2000\n");
    lst_a->count_ra = 0;
	// printf("nbr = %d, nbr div 4 = %d, 400 mod 4 =%d\n", nbr, nbr / 4, nbr % 4);
	// printf("nbr = %d, nbr div 4 = %d, 400 mod 4 =%d\n", 150, 150 / 4, 150 % 4);
	// printf("nbr = %d, nbr div 4 = %d, 400 mod 4 =%d\n", 400, 400 / 4, 400 % 4);
	// printf("nbr = %d, nbr div 4 = %d, 400 mod 4 =%d\n", 500, 500 / 4, 500 % 4);
	// sleep(10);
	//printf("nbr = %d, nbr / 4 = %d , nbr / 8 = %d\n", nbr, nbr / 4, nbr / 8);
	//sleep(1000);
	/*
	**	Creation d'une fonction qui trouve la mediane, quartile 1 et 3
	*/
	ft_find_mediane(nbr, lst_a);
	printf("nombre de chiffres = %d\n", nbr);
	printf("quartile 1 = %d\n", lst_a->q_one);
	printf("mediane = %d\n", lst_a->median);
	printf("quartile 3 = %d \n", lst_a->q_three);

	t_list *tmp_a;

	tmp_a = lst_a->first;
	while (lst_a)
	{
		// printf("Dans boucle principale\n");
		// sleep(2);

		push_first_quartile(nbr, lst_a, lst_b);

		// printf("Ffin de le premiere fonction\n");
        // printf("Dans stack B < a Q1\n");
		// printf("total = %d\n", lst_b->total + lst_a->total);
		// ft_display_lst(lst_a, lst_b);
		// sleep(3);
		//printf("Trie B\n");
		
        //ft_do_ra(lst_a);
        sort_b_to_a(nbr, lst_a, lst_b, 8);

		printf("Find de la deuxieme fonction... \n");
		// printf("total = %d\n", lst_b->total + lst_a->total);
		// sleep(50);


        // printf("counbra = %d\n", lst_a->count_ra);
        // sleep(5);
        while (lst_a->count_ra >= 0)
        {
            ft_do_ra(lst_a);
            lst_a->count_ra--;

        }

		// ft_display_lst(lst_a, lst_b);
        // printf("total = %d\n", lst_b->total + lst_a->total);
		// printf("Find sort b to a 1ere boucle fonction... %d\n", lst_a->total + lst_b->total);
		// sleep(100);



		/*
		**	ON attaque le deuxieme quart!
		*/
		// printf("LOL 1\n");
		// sleep(2);

		push_second_quartile(nbr, lst_a, lst_b);
		
        // printf("LOL 2\n");
		// sleep(1);
		while (lst_a->first->number != lst_a->q_one)
        {

                ft_do_ra(lst_a);

        }
        ft_do_ra(lst_a);
        ft_display_lst(lst_a, lst_b);
		// printf("TEST?... \n");
		// printf("total = %d\n", lst_b->total + lst_a->total);
		// sleep(10);



        sort_b_to_a(nbr, lst_a, lst_b, 8);

		// ft_display_lst(lst_a, lst_b);
		// printf("Find sort b to a 2eme  boucle fonction... \n");
		// printf("LOL 3\n");


        while (lst_a->count_ra >= 0)
        {
            ft_do_ra(lst_a);
            lst_a->count_ra--;

        }
		ft_display_lst(lst_a, lst_b);
		// printf("Fin du trie pour le 2eme quart... \n");
		// printf("total = %d\n", lst_b->total + lst_a->total);
		// sleep(5);




		/*
		**	ON attaque le troisieme quart!
		*/
		// printf("la 1\n");
		// sleep(2);

		push_third_quartile(nbr, lst_a, lst_b);

		// printf("la 2\n");
		// sleep(2);
        while (lst_a->first->number != lst_a->median)
        {

                ft_do_ra(lst_a);

        }
        ft_do_ra(lst_a);


		sort_b_to_a(nbr, lst_a, lst_b, 8);
        while (lst_a->count_ra >= 0)
        {
            ft_do_ra(lst_a);
            lst_a->count_ra--;

        }

		// printf("la 3\n");
		// sleep(2);
        // ft_display_lst(lst_a, lst_b);
		// printf("Fin du trie pour le 3eme quart... \n");
		// printf("total = %d\n", lst_b->total + lst_a->total);
		// sleep(5);


		/*
		**	ON attaque le DERNIER quart!
		*/
		// printf("ici 1\n");
		// sleep(5);
		//push_third_quartile(nbr, lst_a, lst_b);
        push_last_quartile(nbr, lst_a, lst_b);
        // while (lst_a->first->number != lst_a->q_three)
        // {

        //         ft_do_ra(lst_a);

        // }
        // ft_do_ra(lst_a);
		// printf("ici 2\n");
		// sleep(5);

		sort_b_to_a(nbr, lst_a, lst_b, 8);

		// printf("ici 3\n");
		// sleep(2);
		


        // ft_display_lst(lst_a, lst_b);
		// printf("Fin du trie pour le DERNIER quart... \n");
		// printf("total = %d\n", lst_b->total + lst_a->total);

		
		// sleep(10);


		tmp_a = lst_a->first;
		while (ft_ordre_croissant(lst_a, lst_b) != 0)
		{
			if (ft_find_small(lst_a) <= (nbr /2))
			{
				ft_ra(lst_a);
				write(1, "ra\n", 3);
				lst_a->total++;
			}
			else
			{
				ft_rra(lst_a);
				write(1, "rra\n", 4);
				lst_a->total++;
			}
		}
        ft_display_lst(lst_a, lst_b);
		printf("GOOD 0 oui 1 non \t%d\n%d", ft_ordre_croissant(lst_a, lst_b), lst_b->total+lst_a->total);
		printf("total = %d\n", lst_b->total + lst_a->total);
        sleep(50);

		// printf("GGOOD\n");
		// printf("total = %d\n", lst_b->total + lst_a->total);
		sleep(20);
		break;

	}


	(void)tmp_a;








	(void)nbr;
	(void)lst_a;
	(void)lst_b;	
	sleep(10);
	return (0);
}