/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:48:42 by erian             #+#    #+#             */
/*   Updated: 2024/11/27 12:38:47 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_isvalid(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (1);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (1);
	while (*++argv)
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
	return (0);
}

int	duplicate(t_list *stack, int nbr)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	sorted(t_list *stack)
{
	t_list	*temp;

	while (stack && stack->next)
	{
		temp = stack->next;
		if (stack->value > temp->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
