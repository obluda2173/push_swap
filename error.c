/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:22:01 by erian             #+#    #+#             */
/*   Updated: 2024/09/07 10:04:20 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_printf("%s", "Error\n");
	exit (1);
}

void	free_stack(t_list **stack)
{
	t_list	*head;

	while (*stack)
	{
		head = ((*stack)->next);
		free(*stack);
		*stack = head;
	}
}

void	error_free(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_printf("%s", "Error\n");
	exit (1);
}

void	split_free(char **argv_split)
{
	while (*argv_split)
		free(*argv_split);
	free(argv_split);
}
