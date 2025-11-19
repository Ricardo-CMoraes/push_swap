/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:54:45 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/18 23:04:28 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
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
	{
		stack_a->head = first_b;
		stack_a->tail = first_b;
		first_b->next = NULL;
		first_b->prev = NULL;
	}
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
