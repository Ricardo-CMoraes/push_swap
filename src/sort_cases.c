/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rida-cos <rida-cos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:22:35 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/23 11:20:34 by rida-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_rra(t_stack *stack, int n_elem)
{
	if (stack->tail->index == n_elem - 3)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (stack->tail->index == n_elem - 2)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
}

void	sort_3(t_stack *stack, int n_elem)
{
	if (stack->head->index == n_elem - 1)
	{
		if (stack->tail->index == n_elem - 2)
			ra(stack, 1);
		else if (stack->tail->index == n_elem - 3)
			sa_rra(stack, n_elem);
	}
	else if (stack->head->index == n_elem - 2)
	{
		if (stack->tail->index == n_elem - 1)
			sa(stack, 1);
		else if (stack->tail->index == n_elem - 3)
			rra(stack, 1);
	}
	else if (stack->head->index == n_elem - 3)
	{
		if (stack->tail->index == n_elem - 2)
			sa_rra(stack, n_elem);
		else if (stack->tail->index == n_elem - 1)
			return ;
	}
}

void	push_target_to_b(t_stack *stack_a, t_stack *stack_b, int target)
{
	t_stack_node	*node;
	int				pos;
	int				rotations;

	pos = 0;
	node = stack_a->head;
	while (node->index != target)
	{
		node = node->next;
		pos++;
	}
	rotations = stack_a->size;
	if (pos <= (rotations / 2) && !(is_sorted(stack_a)))
	{
		while (pos--)
			ra(stack_a, 1);
	}
	else if (pos > (rotations / 2) && !(is_sorted(stack_a)))
	{
		rotations = rotations - pos;
		while (rotations--)
			rra(stack_a, 1);
	}
	if (!(is_sorted(stack_a)))
		pb(stack_a, stack_b);
}

void	sort_cases(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 1)
		return ;
	if (is_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->head->index > stack_a->tail->index)
			sa(stack_a, 1);
	}
	else if (stack_a->size == 3)
		sort_3(stack_a, 3);
	else if (stack_a->size == 4)
	{
		push_target_to_b(stack_a, stack_b, 0);
		sort_3(stack_a, 4);
		pa(stack_a, stack_b);
	}
	else if (stack_a->size == 5)
	{
		push_target_to_b(stack_a, stack_b, 0);
		push_target_to_b(stack_a, stack_b, 1);
		sort_3(stack_a, 5);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_discretized	*tmp_array;

	tmp_array = create_sorted_array(stack_a->head, stack_a->size);
	fill_index(stack_a, tmp_array);
	free(tmp_array);
	if (stack_a->size <= 5)
		sort_cases(stack_a, stack_b);
	else
	{
		if (is_sorted(stack_a))
			return ;
		radix_sort(stack_a, stack_b);
	}
}
