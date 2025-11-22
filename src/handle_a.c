/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rida-cos <rida-cos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:54:45 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/22 12:39:39 by rida-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int print)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack_a->size < 2)
		return ;
	first = stack_a->head;
	second = stack_a->head->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack_a->head = second;
	if (first->next != NULL)
		first->next->prev = first;
	if (stack_a->size == 2)
		stack_a->tail = first;
	if (print == 1)
		ft_printf("sa\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*first_b;

	if (stack_b->size == 0)
		return ;
	first_b = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_b->head != NULL)
		stack_b->head->prev = NULL;
	else
		stack_b->tail = NULL;
	stack_b->size--;
	if (stack_a->size == 0)
		set_init_stack(stack_a, first_b);
	else
	{
		first_b->next = stack_a->head;
		stack_a->head->prev = first_b;
		first_b->prev = NULL;
		stack_a->head = first_b;
	}
	stack_a->size++;
	ft_printf("pa\n");
}

void	ra(t_stack *stack_a, int print)
{
	t_stack_node	*first_a;

	if (stack_a->size < 2)
		return ;
	first_a = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_a->head->prev = NULL;
	first_a->prev = stack_a->tail;
	first_a->next = NULL;
	stack_a->tail->next = first_a;
	stack_a->tail = first_a;
	if (print == 1)
		ft_printf("ra\n");
}

void	rra(t_stack *stack_a, int print)
{
	t_stack_node	*last_a;

	if (stack_a->size < 2)
		return ;
	last_a = stack_a->tail;
	stack_a->tail = stack_a->tail->prev;
	stack_a->tail->next = NULL;
	last_a->next = stack_a->head;
	last_a->prev = NULL;
	stack_a->head->prev = last_a;
	stack_a->head = last_a;
	if (print == 1)
		ft_printf("rra\n");
}
