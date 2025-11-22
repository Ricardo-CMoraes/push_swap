/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:39:55 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/22 00:55:18 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack_node
{
	int					value; // Valor original (e.g., -5, 100)
	int					index; // Posição ordenada (0, 1, 2...)
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head; // Topo da pilha
	t_stack_node	*tail; // Base da pilha
	int				size;
}	t_stack;

typedef struct s_discretized
{
	int value;
	int index;
}	t_discretized;

//bubble_sort
void swap_nodes(t_discretized *a, t_discretized *b);
void bubble_sort(t_discretized *array, int size);
//discretization
t_discretized *create_sorted_array(t_stack_node *head, int size);
void fill_index(t_stack *stack, t_discretized *tmp_array);
//handle_a
void	sa(t_stack *stack_a);
void	pa(t_stack *stack_a, t_stack *stack_b);
void ra(t_stack *stack_a);
void rra(t_stack *stack_a);
//handle_b
void	sb(t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void rb(t_stack *stack_b);
void rrb(t_stack *stack_b);
//handle_both
void ss(t_stack *stack_a, t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
//handle_linked_list
t_stack_node *new_node(int value);
void	stack_add(int value, t_stack *stack);
//ini_stack
void	set_stack(t_stack *stack);
t_stack	*init_stack(int argc, char **argv);
//radix_sort
void radix_sort(t_stack *a, t_stack *b);
//sort_cases
void sa_rra(t_stack *stack);
void sort_3(t_stack *stack, int n_elem);
void push_target_to_b(t_stack *stack_a, t_stack *stack_b, int target);
void sort_cases(t_stack *stack_a, t_stack *stack_b);
void sort(t_stack *stack_a, t_stack *stack_b);
//utils
void	error_msg(char *str);
int	count_arg(char **array);
void	free_array(char **array);
void free_stack(t_stack *stack);
int get_max_bits(int size);
//validate
int	check_doubles(char **argv);
int	check_nbr(char *argv);
void	check_input(int argc, char **argv);



//void print_stack(t_stack *stack);


#endif