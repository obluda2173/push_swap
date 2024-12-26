/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:13:22 by erian             #+#    #+#             */
/*   Updated: 2024/12/09 10:30:24 by erian            ###   ########.fr       */
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
			error_free(stack_a);
		if (duplicate(*stack_a, (int)nbr))
			error_free(stack_a);
		copy_data(stack_a, (int)nbr);
		i++;
	}
	distance(stack_a);
}

void	stack_init_split(t_list **stack_a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (argv_isvalid(argv[i]))
			error_free_split(stack_a, argv);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free_split(stack_a, argv);
		if (duplicate(*stack_a, (int)nbr))
			error_free_split(stack_a, argv);
		copy_data(stack_a, (int)nbr);
		i++;
	}
	if (argv[0] == NULL)
		error_free_split(stack_a, argv);
	distance(stack_a);
}

void	print_stack(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	ft_printf("%s", "Stack: ");
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
	temp = stack;
	ft_printf("%s", "Distance: ");
	while (temp)
	{
		ft_printf("%d ", temp->distance);
		temp = temp->next;
	}
	ft_printf("\n");
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
	else
		radix_sort(stack_a, stack_b);
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
		stack_init_split(&stack_a, argv);
		free_split(argv);
	}
	else if (argc > 2)
		stack_init(&stack_a, argv + 1);
	if (!sorted(stack_a))
		distribute_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

/*
EXTRAVAGANT INPUTS:
valgrind --show-leak-kinds=all ./push_swap 2 ONE 3 5 FOUR
valgrind --show-leak-kinds=all ./push_swap a
valgrind --show-leak-kinds=all ./push_swap a b
valgrind --show-leak-kinds=all ./push_swap a b c
valgrind --show-leak-kinds=all ./push_swap "a"
valgrind --show-leak-kinds=all ./push_swap "a b c"
valgrind --show-leak-kinds=all ./push_swap " "
valgrind --show-leak-kinds=all ./push_swap ""
valgrind --show-leak-kinds=all ./push_swap " " " "
valgrind --show-leak-kinds=all ./push_swap "" ""

DUPLICATES:
valgrind --show-leak-kinds=all ./push_swap 1 2 2 3 4
valgrind --show-leak-kinds=all ./push_swap 1 3 2 2 4
valgrind --show-leak-kinds=all ./push_swap "1 2 2 3 4"
valgrind --show-leak-kinds=all ./push_swap "1 3 2 2 4"

MAX AND MIN INT:
valgrind --show-leak-kinds=all ./push_swap 1 2147483647 2
valgrind --show-leak-kinds=all ./push_swap 1 2147483648 2
valgrind --show-leak-kinds=all ./push_swap 1 -2147483648 2
valgrind --show-leak-kinds=all ./push_swap 1 -2147483649 2

IDENTITY TEST:
valgrind --show-leak-kinds=all ./push_swap 42
valgrind --show-leak-kinds=all ./push_swap "42"
valgrind --show-leak-kinds=all ./push_swap 2 3
valgrind --show-leak-kinds=all ./push_swap 0 1 2 3
valgrind --show-leak-kinds=all ./push_swap 0 1 2 3 4 5 6 7 8 9
valgrind --show-leak-kinds=all ./push_swap "0 1 2 3 4 5 6 7 8 9"
valgrind --show-leak-kinds=all ./push_swap 3 2 5 6 4 1 7 8 9 0
valgrind --show-leak-kinds=all ./push_swap "3 2 5 6 4 1 7 8 9 0"

CHECKER
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
ARG=""; ./push_swap $ARG | ./checker_linux $ARG

RANDOM NUMBERS GENERATOR
https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php
*/
