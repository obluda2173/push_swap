/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:13:22 by erian             #+#    #+#             */
/*   Updated: 2024/09/09 18:59:19 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_list **stack_a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (argv_isvalid(argv[i]))
			error_free(stack_a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error();
		if (duplicate(*stack_a, (int)nbr))
			error();
		copy_data(stack_a, (int)nbr);
		i++;
	}
}

void print_stack(t_list *stack)
{
    while (stack)
    {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
    ft_printf("%c", "\n");
}

void	distribute_sort(t_list **stack_a, t_list **stack_b)
{
	if (stack_len(*stack_a) == 2)
			ra(stack_a);
		else if (stack_len(*stack_a) == 3)
			sort_3(stack_a);
		else if (stack_len(*stack_a) == 4)
			sort_4(stack_a, stack_b);
		else if (stack_len(*stack_a) == 5)
			sort_5(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_init(&stack_a, argv);
	}
	else if (argc > 2)
		stack_init(&stack_a, argv + 1);
	if (!sorted(stack_a))
		distribute_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
