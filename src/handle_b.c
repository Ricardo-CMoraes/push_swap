/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:55:04 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/19 00:43:04 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_stack *stack_b)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack_b->size < 2)
		return ;
	first = stack_b->head;
	second = stack_b->head->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack_b->head = second;
	if (first->next != NULL)
		first->next->prev = first;
	if (stack_b->size == 2)
		stack_b->tail = first;
	ft_printf("sb\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_stack_node	*first_a;

	if (stack_a->size == 0)
		return ;
	first_a = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_a->head != NULL)
		stack_a->head->prev = NULL;
	else
		stack_a->tail = NULL;
	stack_a->size--;
	if (stack_a->size == 0)
	{
		stack_a->head = first_a;
		stack_a->tail = first_a;
		first_a->next = NULL;
		first_a->prev = NULL;
	}
	else
	{
		first_a->next = stack_a->head;
		stack_a->head->prev = first_a;
		first_a->prev = NULL;
		stack_a->head = first_a;
	}
	stack_a->size++;
	ft_printf("pb\n");
}

void rb(t_stack *stack_b)
{
	t_stack_node *first_b;

	if (stack_b->size < 2)
		return ;
	first_b = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->head->prev = NULL;
	first_b->prev = stack_b->tail;
	first_b->next = NULL;
	stack_b->tail->next = first_b;
	stack_b->tail = first_b;	
	ft_printf("rb\n");
}
