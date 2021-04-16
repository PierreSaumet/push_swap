/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaumet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:06 by psaumet           #+#    #+#             */
/*   Updated: 2019/11/22 13:33:53 by psaumet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/push_swap.h"

/*
**  This file contains 3 functions:
**  -'static void	ft_error(void)':	Display Error
**	-'int     ft_check_args(int argc, char **argv, int i)':	Checks how many
**	arguments were given and if they are digit.
**	-int	ft_count(int argc, char **argv, int count)':	Count the total
**	of numbers form the arguments.
*/

int					ft_count(int argc, char **argv, int count)
{
	int				i;

	i = 0;
	argc = argc - 1;
	while (argc > 0)
	{
		i = 0;
		while (argv[argc][i])
		{
			if ((argv[argc][i] == '-' || argv[argc][i] == '+')
					&& ft_isdigit(argv[argc][i + 1]) == 1)
				i++;
			else if (ft_isdigit(argv[argc][i]) == 1)
			{
				if (argv[argc][i + 1] == ' ' || argv[argc][i + 1] == '\0')
					count++;
				i++;
			}
			else
				i++;
		}
		argc--;
	}
	return (count);
}

static void			ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int					ft_check_args(int argc, char **argv, int i)
{
	if (argc + 1 < 2)
		return (1);
	else
	{
		while (argc > 0)
		{
			while (argv[argc][i])
			{
				if (ft_isdigit(argv[argc][i]) == 0)
				{
					if (((argv[argc][i] == '-' || argv[argc][i] == '+')
							&& ft_isdigit(argv[argc][i + 1]))
							|| argv[argc][i] == ' ')
						i++;
					else
						ft_error();
				}
				else
					i++;
			}
			argc--;
			i = 0;
		}
		return (0);
	}
}
