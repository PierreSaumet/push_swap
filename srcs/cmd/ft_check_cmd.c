/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/checker.h"

int     ft_check_cmd(char *line, t_data *lst_a, t_data *lst_b)
{
    if (ft_strcmp(line, "sa") == 0)
    {
        // ft_sa
        printf("cas SA\n");
        ft_sa(lst_a);
    }
    else if (ft_strcmp(line, "sb") == 0)
    {
        // ft_sb
        printf("cas SB\n");
        ft_sb(lst_b);
    }
    else if (ft_strcmp(line, "ss") == 0)
    {
        // ft_ss
        printf("cas SS\n");
        ft_sa(lst_a);
        ft_sb(lst_b);
    }
    else if (ft_strcmp(line, "pa") == 0)
    {
        // ft_pa
        printf("cas PA\n");
        return(ft_pa(lst_a, lst_b));
    }
    else if (ft_strcmp(line, "pb") == 0)
    {
        // ft_pb
        printf("cas PB\n");
        return(ft_pb(lst_a, lst_b));
    }
    else if (ft_strcmp(line, "ra") == 0)
    {
        // ft_ra
        printf("cas RA\n");
        return(ft_ra(lst_a));
    }
    else if (ft_strcmp(line, "rb") == 0)
    {
        // ft_rb
        printf("cas RB\n");
        return(ft_rb(lst_b));
    }
    else if (ft_strcmp(line, "rr") == 0)
    {
        // ft_rr
        printf("cas RR\n");
        ft_ra(lst_a);
        ft_rb(lst_b);
    }
    else if (ft_strcmp(line, "rra") == 0)
    {
        // ft_rra
        printf("cas RRA\n");
        return(ft_rra(lst_a));
    }
    else if (ft_strcmp(line, "rrb") == 0)
    {
        // ft_rrb
        printf("cas RRB\n");
        return (ft_rrb(lst_b));
    }
    else if (ft_strcmp(line, "rrr") == 0)
    {
        /// ft_rrr
        printf("cas RRR\n");
        ft_rra(lst_a);
        ft_rrb(lst_b);
    }
    else
    {
        printf("ERREUR CMD\n");
        return (1);
    }
    return (0);
}