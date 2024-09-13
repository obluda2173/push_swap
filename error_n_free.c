/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_n_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:22:01 by erian             #+#    #+#             */
/*   Updated: 2024/09/10 22:15:40 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_printf("%s", "Error");
	ft_printf("\n");
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

void	error_free(t_list **stack)
{
	free_stack(stack);
	error();
}

void	free_split(char **argv)
{
	while (*argv)
	{
		free(*argv);
		argv++;
	}
}
