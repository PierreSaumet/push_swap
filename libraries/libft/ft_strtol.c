/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:05:30 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 11:05:44 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

float		ft_power(int nb, int exp)
{
	float		result;

	if (exp == 0)
		return (1);
	result = ft_power(nb, exp / 2);
	if (exp % 2 == 0)
		return (result * result);
	else
	{
		if (exp > 0)
			return (nb * result * result);
		else
			return (result * result) / nb;
	}
}

long int	ft_strtol(char *line)
{
	long int	rslt;
	long int	*hexa;
	int			cmp;
	int			power;

	cmp = 0;
	power = 0;
	rslt = 0;
	hexa = (long int*)malloc(sizeof(long int) * ft_strlen(line));
	while (line[cmp])
	{
		if (line[cmp] >= 'A' && line[cmp] <= 'F')
			hexa[cmp] = line[cmp] + 10 - 'A';
		else if (line[cmp] >= '0' && line[cmp] <= '9')
			hexa[cmp] = line[cmp] - '0';
		cmp++;
	}
	while (--cmp >= 0)
	{
		rslt += hexa[cmp] * ft_power(16, power);
		power++;
	}
	free(hexa);
	return (rslt);
}
