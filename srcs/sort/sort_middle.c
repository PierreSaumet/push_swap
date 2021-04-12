/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

/*
**  A creer:
**              une fonction qui trouve la valeur la plus grande de la stack en fonction de la mediane
**              une fonction qui trouve la valeur la plus petite de la stack en fonction de la mediane
**              une fonction qui trouve le quart et le 3 quart
*/

/*
**	Donne la longueur de la liste donnee
*/
int         ft_len_list(t_data *lst)
{
	t_list *tmp;
	int     i;

	i = 0;
	tmp = lst->first;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*
**	Trouve le plus petit chiffre en fonction de la mediane donnee
*/
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
		//printf("tmp->number = %d\n", tmp->number);
		if (min > tmp->number && tmp->number < med)
		{
			min = tmp->number;
			//printf("min = %d\n", min);
		}
		tmp = tmp->next;
	}

	return (min);
}

/*
**	Trouve le plus grand chiffre en fonction de la mediane donnee
*/
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
		//printf("tmp->number = %d\n", tmp->number);
		if (max < tmp->number && tmp->number < med)
		{
			max = tmp->number;
			//printf("min = %d\n", min);
		}
		tmp = tmp->next;
	}

	return (max);
}

/*
**	Trouve l'emplacement du chiffre le plus grand inferieur a la mediane
*/
int         ft_find_big_med(int med, t_data *lst)
{
    t_list  *tmp;
    int     emp;
    int     max;

    if (lst == NULL)
		exit(EXIT_FAILURE);
    tmp = lst->first;
    emp = 1;
    max = -2147483648;
    while (tmp != NULL)
	{
		//printf("tmp->number = %d\n", tmp->number);
		if (max < tmp->number && tmp->number <= med)
		{
			max = tmp->number;
			//printf("max = %d\n", max);
		}
		tmp = tmp->next;
	}
	//printf("dans big med = %d\n", max);
    tmp = lst->first;
    while (tmp->number != max)
    {
        emp++;
        tmp = tmp->next;
    }
	//printf("emplacement du big de mediane = %d\n", emp);
	//sleep(10);
    return (emp);
}

int             ft_do_rb(t_data *lst)
{
    ft_rb(lst);
	printf("1\n");
	write(1, "rb\n", 3);
	lst->total++;
    return (0);
}

int             ft_do_rrb(t_data *lst)
{
    ft_rrb(lst);
	printf("2\n");
	write(1, "rrb\n", 4);
	lst->total++;
    return (0);
}

int             ft_end_find_best(int diff_min, int diff_max, t_data *lst, int div)
{
    if (diff_min > diff_max)
	{
		if (ft_find_small(lst) < (lst->nbr / div))
			ft_do_rb(lst);
		else
			ft_do_rrb(lst);
	}
	else
	{
		if (ft_find_big(lst) < (lst->nbr / div))
			ft_do_rb(lst);
		else
			ft_do_rrb(lst);
	}	
    return (0);
}

int				ft_find_best(int nbr, t_data *lst, int div)
{
	//printf("Dans find_best\n");
	int			diff_min;
	int			diff_max;

	if (lst == NULL)
		return (1);
	diff_min = ft_find_small(lst) - nbr;
	diff_max = ft_find_big(lst) - nbr;
	if (ft_len_list(lst) == 1)
		return (-1);
	if (ft_find_small(lst) < (nbr / div) && ft_find_big(lst) < (nbr / div))
		ft_do_rb(lst);
	else if (ft_find_small(lst) > (nbr / div) && ft_find_big(lst) > (nbr / div))
		ft_do_rrb(lst);
	else
        ft_end_find_best(diff_min, diff_max, lst, div);

	return (0);
}

int             ft_do_pb(t_data *lst_a, t_data *lst_b)
{
    ft_pb(lst_a, lst_b);
	write(1, "pb\n", 3);
    lst_a->total++;
    return (0);
}

int             ft_do_ra(t_data *lst_a)
{
    ft_ra(lst_a);
	write(1, "ra\n", 3);
	lst_a->total++;
    return (0);
}

int             ft_do_rra(t_data *lst_a)
{
    ft_rra(lst_a);
	write(1, "rra\n", 3);
	lst_a->total++;
    return (0);
}


int             ft_first_middle(int nbr, t_data *lst_a, t_data *lst_b)
{
    t_list      *tmp_a;
    int         mediane;
    int         c;

    tmp_a = lst_a->first;
    mediane = find_mediane(nbr, lst_a);
    c = 0;
    while (1)
	{
		if (tmp_a->number <= mediane)
		{
            if (lst_b->first && lst_b->first->number > mediane / 2)
                ft_do_rb(lst_b);
            ft_do_pb(lst_a, lst_b);
			// ft_pb(lst_a, lst_b);
			// write(1, "pb\n", 3);
            // lst_a->total++;
			c++;
			if (nbr % 2 == 1)
			{
				if (c == (nbr + 1) / 2)
					break;				
			}
			else
			{
				if (c == nbr / 2)
					break;
			}
		}
		else
		{
            ft_do_ra(lst_a);
			// ft_ra(lst_a);
			// write(1, "ra\n", 3);
			// lst_a->total++;
		}
		tmp_a = lst_a->first;
	}
    return (0);
}


int             test(int nbr, t_data *lst_a, t_data *lst_b)
{
	int         mediane;
	int			total;

	lst_a->total = 0;
	lst_b->total = 0;
	/*
	**  Etape 1: Trouver la mediane
	*/
	total = 0;
	mediane = find_mediane(nbr, lst_a);     // si pair OK
	printf("Mediane = %d\n", mediane);
	printf("Nombre de chiffres: %d\n", nbr);
	printf("Emplacement du plus petit: %d\n", ft_find_small(lst_a));
	printf("Emplacement du plus grand: %d\n", ft_find_big(lst_a));
	printf("Taille de la liste : %d\n", ft_len_list(lst_a));
	printf("Nombre des actions totales: %d\n", total);
	printf("nbr = %d nbr mod 2 = %d\n", nbr, nbr % 2);
	sleep(10);
	ft_display_lst(lst_a, lst_b);

	/*
	**  Mettre dans la stack B tous les nombres < a la mediane
	**		STATUT : etape 2 OK
	*/
	t_list		*tmp_a;
	int 		c;

	tmp_a = lst_a->first;
	c = 0;
    ft_first_middle(nbr, lst_a, lst_b);
	// printf("fin de la premiere boucle = etape 2\n");
	// sleep(1);
	// ft_display_lst(lst_a, lst_b);
	// printf("total = %d\n", total + lst_b->total + lst_a->total);
	// sleep(5);

	/*
	**	Etape 3:
	**				Mets le plus petit de B au fond de A
	**				Mets le plus grand de B au debut de A
	**			STATUT : OK
	*/
	t_list	*tmp_b;

	tmp_b = lst_b->first;
	c = 0;
	tmp_a = lst_a->first;
	while (tmp_b != NULL)
	{
		printf("Le plus petit de B = %d\n", ft_find_small(lst_b));
		printf("Le plus grand de B = %d\n", ft_find_big(lst_b));
		if (ft_find_small(lst_b) == 1)
		{
			ft_pa(lst_a, lst_b);
			write(1, "pa\n", 3);
			total++;
			c++;
			ft_ra(lst_a);
			write(1, "ra\n", 3);
			total++;
		}
		else if (ft_find_big(lst_b) == 1)
		{
			ft_pa(lst_a, lst_b);
			write(1, "pa\n", 3);
			total++;
			c++;
		}
		if (ft_find_best(nbr, lst_b, 4) == -1)
		{
			ft_pa(lst_a, lst_b);
			write(1, "pa\n", 3);
			total++;
			c++;
		}
		tmp_b = lst_b->first;
	}
	printf("fin de la deuxieme boucle = etape 3\n");
			sleep(2);
	ft_display_lst(lst_a, lst_b);
	printf("total = %d\n", total + lst_b->total + lst_a->total);
	sleep(2);

	/*
	**	Etape 4:		et 5 ?
	**				Mets dans la stack B tout superieur a mediane
	*/
	tmp_a = lst_a->first;
	while (ft_ordre_croissant(lst_a, lst_b) != 0)
	{
		if (tmp_a->number > mediane)
		{
			ft_pb(lst_a, lst_b);
			write(1, "pb\n", 3);
			total++;
		}
		else
		{
			ft_ra(lst_a);
			write(1, "ra\n", 3);
			total++;
		}
		if (total > 300)
		{
			break ;
		}
		tmp_a = lst_a->first;
	}
	printf("fin de la troisieme boucle = etape 4-5\n");
			sleep(2);
	ft_display_lst(lst_a, lst_b);
	printf("total = %d\n", total + lst_b->total + lst_a->total);
	sleep(2);



	/*
	**	Etape 6 et 7:
	**					Mets le plus petit de B dans A 
	*/
	tmp_b = lst_b->first;
	c = 0;
	tmp_a = lst_a->first;
	while (tmp_b != NULL)
	{
		printf("Le plus petit de B = %d\n", ft_find_small(lst_b));
		printf("Le plus grand de B = %d\n", ft_find_big(lst_b));
		
		if (ft_find_small(lst_b) == 1)
		{
			ft_pa(lst_a, lst_b);
			write(1, "pa\n", 3);
			total++;
			c++;
			ft_ra(lst_a);
			write(1, "ra\n", 3);
			total++;
		}
		else if (ft_find_big(lst_b) == 1)
		{
			ft_pa(lst_a, lst_b);
			write(1, "pa\n", 3);
			total++;
			c++;
		}
		if (ft_find_best(nbr, lst_b, 4) == -1)
		{
			ft_pa(lst_a, lst_b);
			write(1, "pa\n", 3);
			total++;
			c++;
		}
		tmp_b = lst_b->first;
		// ft_display_lst(lst_a, lst_b);
		// sleep(2);
	}
	printf("fin de la quatrieme boucle = etape 6-7\n");
			sleep(2);
	ft_display_lst(lst_a, lst_b);

	printf("total = %d\n", total + lst_b->total + lst_a->total);
		sleep(2);
	/*
	**	Ultime etape
	*/
	tmp_a = lst_a->first;
	while (ft_ordre_croissant(lst_a, lst_b) != 0)
	{
		if (ft_find_small(lst_a) <= (nbr /2))
		{
			ft_ra(lst_a);
			write(1, "ra\n", 3);
			total++;
		}
		else
		{
			ft_rra(lst_a);
			write(1, "rra\n", 4);
			total++;
		}
	}
	printf("fin de la DERNIERE boucle = etape 8\n");
			sleep(2);
	ft_display_lst(lst_a, lst_b);
	printf("OK = )total = %d\n", total + lst_b->total + lst_a->total);
	exit(EXIT_SUCCESS);
	sleep(10);
	(void)nbr;
	(void)lst_a;
	(void)lst_b;
	return (0);
}