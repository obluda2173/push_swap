/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:34:53 by erian             #+#    #+#             */
/*   Updated: 2024/09/08 12:05:22 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	find_last_node(*stack)->next = temp;
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("%s", "ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("%s", "rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("%s", "rr\n");
}
