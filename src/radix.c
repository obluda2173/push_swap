/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:30:32 by erian             #+#    #+#             */
/*   Updated: 2024/12/09 10:49:52 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->distance;
	max_bits = 0;
	while (head)
	{
		if (head->distance > max)
			max = head->distance;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		digit;
	int		size;
	t_list	*tmp;

	i = 0;
	size = stack_len(*stack_a);
	digit = get_max_bits(stack_a);
	tmp = *stack_a;
	while (i < digit)
	{
		j = 0;
		while (j++ < size)
		{
			tmp = *stack_a;
			if ((tmp->distance >> i & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (stack_len(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
