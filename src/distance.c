/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:50:00 by erian             #+#    #+#             */
/*   Updated: 2024/09/10 12:58:32 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack_a)
{
	t_list	*temp;
	t_list	*min;

	temp = *stack_a;
	min = NULL;
	while (temp)
	{
		if (temp->distance == -1 && (!min || temp->value < min->value))
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	distance(t_list **stack_a)
{
	t_list	*min_node;
	int		i;

	i = 0;
	min_node = get_next_min(stack_a);
	while (min_node != NULL)
	{
		min_node->distance = i;
		i++;
		min_node = get_next_min(stack_a);
	}
}
