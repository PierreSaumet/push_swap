/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int     ft_get_cmd(t_data *lst_a, t_data *lst_b)
{
    char    *line;
 
    line = NULL;
    //printf("\n\nDEBUT GNL\n");
    while ((get_next_line(0, &line) == 1))
    {
        if (ft_check_cmd(line, lst_a, lst_b) == 0)
            free(line);
        else
        {
            free(line);
            return (1);
        }
        //ft_display_lst(lst_a, lst_b);
    }
    free(line);
    return (0);
}

int        ft_start(int nbr, char **argv)
{
    t_data      *lst_a;
    t_data      *lst_b;

    lst_a = initialize_list(nbr, argv);
    lst_b = initialize_listb();
    ft_full_insertion(lst_a, nbr - 1, argv);


    // ft_display_lst(lst_a, lst_b);
    // sleep(5);
    if ((ft_get_cmd(lst_a, lst_b) == 1))
    {
        ft_free_all(lst_a, lst_b); 
        return (1);
    }

    ft_end(lst_a, lst_b);

    ft_display_lst(lst_a, lst_b);
    ft_free_all(lst_a, lst_b);     
    return (0);            
}

void    ft_initialize_c(int nbr, int argc, char **argv)
{
	char **tab;

	tab = NULL;
	tab = ft_malloc_tab(nbr, argc, argv);
	tab = ft_get_nbr(argc - 1, argv, tab, nbr);
	tab = ft_clean_tab(tab, nbr);
	tab = ft_del_space(tab, nbr);
	tab = ft_check_zero(tab, nbr, 0, 0);
	ft_check_int(tab, nbr);
	ft_duplicate(tab, nbr);

	// START THE PROGRAMME then free the numbers 
	ft_start(nbr, tab);
	ft_free_tab(tab, nbr);
}

int     main(int argc, char **argv)
{
	int ret;

	ret = ft_check_args(argc - 1, argv, 0);
	if (ret == 1)
		return (1);
	else
	{
		ret = ft_count(argc, argv, 0);
		if (ret == 0)
			return (1);
		ft_initialize_c(ret, argc, argv);  
	}
	return (0);
}