/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:15:20 by erian             #+#    #+#             */
/*   Updated: 2024/09/07 20:16:12 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/Libft/libft.h"

typedef struct s_list
{
	int				value;
	int				distance;
	struct s_list	*next;
}					t_list;

int		main(int argc, char **argv);
void	stack_init(t_list **stack_a, char **argv);
void	copy_data(t_list **stack, int nbr);
void	error(void);
void	free_stack(t_list **stack);
void	error_free(t_list **stack_a);
int		argv_isvalid(char *argv);
int		duplicate(t_list *argv, int nbr);
t_list	*find_last_node(t_list *stack);
int		sorted(t_list *stack);

#endif