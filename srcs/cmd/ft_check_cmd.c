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

#include "../../headers/push_swap.h"

/*
**	This file contains 1 function:
**	-'int			ft_check_cmd(char *line, t_data *lst_a, t_data *lst_b)':
**	One main functions of the program. Check the command from the prompt.
**	Careful to the return, need to be change...
*/

int			ft_rr(t_data *lst_a, t_data *lst_b)
{
	ft_ra(lst_a);
	ft_rb(lst_b);
	return (0);
}

int			ft_ss(t_data *lst_a, t_data *lst_b)
{
	ft_sa(lst_a);
	ft_sb(lst_b);
	return (0);
}

int			ft_rrr(t_data *lst_a, t_data *lst_b)
{
	ft_rra(lst_a);
	ft_rrb(lst_b);
	return (0);
}

int			ft_check_cmd(char *line, t_data *lst_a, t_data *lst_b)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(lst_a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(lst_b);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(lst_a, lst_b);
	else if (ft_strcmp(line, "pa") == 0)
		return (ft_pa(lst_a, lst_b));
	else if (ft_strcmp(line, "pb") == 0)
		return (ft_pb(lst_a, lst_b));
	else if (ft_strcmp(line, "ra") == 0)
		return (ft_ra(lst_a));
	else if (ft_strcmp(line, "rb") == 0)
		return (ft_rb(lst_b));
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(lst_a, lst_b);
	else if (ft_strcmp(line, "rra") == 0)
		return (ft_rra(lst_a));
	else if (ft_strcmp(line, "rrb") == 0)
		return (ft_rrb(lst_b));
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(lst_a, lst_b);
	else
		return (1);
	return (0);
}
