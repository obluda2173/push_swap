/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:15:20 by erian             #+#    #+#             */
/*   Updated: 2024/09/09 18:57:12 by erian            ###   ########.fr       */
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

/* ************************************************************************** */
/* push_swap.c                                                              * */
/* ************************************************************************** */
int		main(int argc, char **argv);
void	stack_init(t_list **stack_a, char **argv);
void	distribute_sort(t_list **stack_a, t_list **stack_b);
void 	print_stack(t_list *stack);
/* ************************************************************************** */
/* list.c                                                                   * */
/* ************************************************************************** */
void	copy_data(t_list **stack, int nbr);
t_list	*find_last_node(t_list *stack);
int		stack_len(t_list *stack);
/* ************************************************************************** */
/* error.c                                                                  * */
/* ************************************************************************** */
void	error(void);
void	free_stack(t_list **stack);
void	error_free(t_list **stack_a);
void	split_free(char **argv_split);
/* ************************************************************************** */
/* checker.c                                                                * */
/* ************************************************************************** */
int		argv_isvalid(char *argv);
int		duplicate(t_list *argv, int nbr);
int		sorted(t_list *stack);
/* ************************************************************************** */
/* little_sort.c                                                            * */
/* ************************************************************************** */
int		find_min(t_list *stack_a);
void 	to_top(t_list **stack_a, int index, int size);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
/* ************************************************************************** */
/* swap                                                                     * */
/* ************************************************************************** */
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
/* ************************************************************************** */
/* push                                                                     * */
/* ************************************************************************** */
void	push(t_list **stack1, t_list **stack2);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
/* ************************************************************************** */
/* rotate                                                                   * */
/* ************************************************************************** */
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
/* ************************************************************************** */
/* reverse_rotate                                                           * */
/* ************************************************************************** */
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);


#endif