/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:48:42 by erian             #+#    #+#             */
/*   Updated: 2024/09/06 19:55:51 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_isvalid(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j])) && (argv[i][j] != ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicate(char **argv)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (argv[i])
	{
		while (argv[i][k])
			k++;
		j = i + 1;
		while (argv[j])
		{
			if (ft_strncmp(argv[i], argv[j], k) == 0)
				return (1);
			j++;
		}
		i++;
		k = 0;
	}
	return (0);
}

