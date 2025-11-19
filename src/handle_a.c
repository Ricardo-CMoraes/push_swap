/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:54:45 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/19 00:43:15 by rdcm             ###   ########.fr       */
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

void ra(t_stack *stack_a)
{
	t_stack_node *first_a;

	if (stack_a->size < 2)
		return ;
	first_a = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_a->head->prev = NULL;
	first_a->prev = stack_a->tail;
	first_a->next = NULL;
	stack_a->tail->next = first_a;
	stack_a->tail = first_a;	
	ft_printf("ra\n");
}

void rra(t_stack *a)
{
    if (a->size < 2)
        return;

    // 1. O antigo tail vai para o topo (head)
    t_stack_node *old_tail = a->tail;
    
    // 2. O 2º último elemento se torna o novo tail
    a->tail = a->tail->prev;
    a->tail->next = NULL;
    
    // 3. O antigo tail se conecta ao topo
    old_tail->next = a->head;
    old_tail->prev = NULL;

    // 4. O antigo head aponta para o novo head (old_tail)
    a->head->prev = old_tail;
    a->head = old_tail; // Atualiza o head

    ft_putstr("rra\n");
}

// As funções rr, rb, rrb, rrr usam lógica idêntica ou chamam as funções base.