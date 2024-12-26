/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:45:35 by erian             #+#    #+#             */
/*   Updated: 2024/09/09 11:56:30 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*temp;

	if (!*stack2)
		return ;
	temp = *stack2;
	*stack2 = temp->next;
	temp->next = *stack1;
	*stack1 = temp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("%s", "pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("%s", "pb\n");
}
