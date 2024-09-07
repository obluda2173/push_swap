/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:13:22 by erian             #+#    #+#             */
/*   Updated: 2024/09/07 10:08:00 by erian            ###   ########.fr       */
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
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error();
		if (duplicate(argv))
			error();
		copy_data(stack_a, nbr);
		argv++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	//t_list	*stack_b;
	char	**argv_split;

	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (0);

	if (argc == 2)
	{
		argv_split = ft_split(argv[1], ' ');
		argv = argv_split;
	}

	if (!argv_isvalid(argv + 1))
	{
		split_free(argv_split);
		error();
	}

	stack_a = NULL;
	//stack_b = NULL;

	stack_init(&stack_a, argv + 1);

	while (stack_a)
	{
		ft_printf("s", stack_a->value);
		stack_a = stack_a->next;
	}
	free_stack(stack_a);
	free_split(argv_split);
	return (0);
}
