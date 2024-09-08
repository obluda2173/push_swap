/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:13:22 by erian             #+#    #+#             */
/*   Updated: 2024/09/08 18:35:53 by erian            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	// t_list	*stack_b;

	stack_a = NULL;
	// stack_b = NULL;

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
	{
		if (stack_len(stack_a) == 2)
			sort_2(&stack_a);
		if (stack_len(stack_a) == 3)
			sort_3(&stack_a);
	}

/* ############################################################### */
/* ############################################################### */

	// sa(&stack_a);

	// ra(&stack_a);

	// rra(&stack_a);

	// t_list	*temp = stack_a;
	// while (temp)
    // {
    //     ft_printf("%d\n", temp->value);
    //     temp = temp->next;
    // }

	// if (sorted(stack_a))
	// 	ft_printf("%s", "stack is sorted?");

/* ############################################################### */
/* ############################################################### */

	free_stack(&stack_a);
	return (0);
}
