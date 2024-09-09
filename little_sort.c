/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:17:37 by erian             #+#    #+#             */
/*   Updated: 2024/09/09 15:51:12 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack_a)
{
	int		i;
	int		value;
	int		index;

	i = 0;
	value = stack_a->value;
	index = 0;
	while (stack_a)
	{
		if (value > stack_a->value)
		{
			value = stack_a->value;
			index = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	return (index);
}

void to_top(t_list **stack_a, int index, int size)
{
	if (index <= size / 2)
    {
        while (index-- > 0)
            ra(stack_a);
    }
    else
    {
        while (++index < size)
            rra(stack_a);
    }
}

void	sort_3(t_list **stack_a)
{
	if (find_min(*stack_a) == 0)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (find_min(*stack_a) == 1)
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

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	to_top(stack_a, find_min(*stack_a), 4);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	to_top(stack_a, find_min(*stack_a), 5);
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
