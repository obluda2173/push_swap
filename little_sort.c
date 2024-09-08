/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:17:37 by erian             #+#    #+#             */
/*   Updated: 2024/09/08 18:37:43 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **stack_a)
{
	t_list	*temp;
	int		i;
	int		value;
	int		index;

	temp = *stack_a;
	i = 0;
	value = temp->value;
	while (temp)
	{
		if (value > temp->value)
		{
			value = temp->value;
			index = i;
		}
		i++;
		temp = temp->next;
	}
	return (index);
}

void	sort_2(t_list **stack_a)
{
	ra(stack_a);
}

void	sort_3(t_list **stack_a)
{
	if (find_min(stack_a) == 0)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (find_min(stack_a) == 1)
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			sa(stack_a);
		else
			ra(stack_a);
	}
	else
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			rra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}
