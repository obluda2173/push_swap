/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:38:39 by erian             #+#    #+#             */
/*   Updated: 2024/09/08 18:31:00 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_last_node(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	copy_data(t_list **stack, int nbr)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->next = NULL;
	new_node->distance = -1;
	if (!(*stack))
	{
		*stack = new_node;
		(*stack)->next = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node;
	}
}

int	stack_len(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
