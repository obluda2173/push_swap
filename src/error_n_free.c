/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_n_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:22:01 by erian             #+#    #+#             */
/*   Updated: 2024/12/08 12:47:50 by erian            ###   ########.fr       */
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

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

void	error_free(t_list **stack)
{
	if (stack && *stack)
	{
		free_stack(stack);
		*stack = NULL;
	}
	error();
}

void	error_free_split(t_list **stack, char **argv)
{
	free_split(argv);
	error_free(stack);
}
