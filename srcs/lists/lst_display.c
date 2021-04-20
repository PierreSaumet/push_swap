/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:50:34 by psaumet           #+#    #+#             */
/*   Updated: 2019/12/20 17:07:02 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**	This file contains 2 functions:
**	-'int	ft_display_lst(t_data *lista, t_data *listb)':
**			WARNING this function is used only for displaying lists
**			Not used...
**	-'void	ft_display_info(int nbr, t_data *lst_a, t_data *lst_b)':
**			WARNING this function is used only for displaying informations
**			Not used...
*/

void			ft_display_info(int nbr, t_data *lst_a, t_data *lst_b)
{
	printf("SOLVE TEST <100\n");
	printf("Q1 = %d\n", lst_a->q_one);
	printf("Mediane = %d\n", lst_a->median);
	printf("Q3 = %d \n", lst_a->q_three);
	printf("Nombre de chiffres: %d\n", nbr);
	printf("Emplacement du plus petit: %d\n", ft_find_small(lst_a));
	printf("Emplacement du plus grand: %d\n", ft_find_big(lst_a));
	printf("Taille de la liste : %d\n", ft_len_list(lst_a));
	printf("Nombre des actions totales: %d\n", lst_a->total + lst_b->total);
	printf("nbr = %d nbr mod 2 = %d\n", nbr, nbr % 2);
	sleep(5);
	sleep(2);
}
