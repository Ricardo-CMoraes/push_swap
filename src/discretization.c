/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discretization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:23:30 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/20 21:31:45 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_discretized *create_sorted_array(t_stack_node *head, int size)
{
	t_discretized	*tmp_array;
	t_stack_node	*current;
	int				i;

	tmp_array = (t_discretized *)malloc(sizeof(t_discretized) * size);
	if (!tmp_array)
		return NULL;
	
	current = head;
	i = 0;
	while (current)
	{
		tmp_array[i].value = current->value;
		tmp_array[i].index = 0;
		current = current->next;
		i++;
	}
	bubble_sort(tmp_array, size);
	i = 0;
	while (i < size)
	{
		tmp_array[i].index = i;
		i++;
	}
	return (tmp_array);
}

void fill_index(t_stack *stack, t_discretized *tmp_array)
{
	t_stack_node	*node;
	int				i;

	node = stack->head;
	while (node)
	{
		i = 0;
		while (i < stack->size)
		{
			if (node->value == tmp_array[i].value)
			{
				node->index = tmp_array[i].index;
				break;
			}
			i++;
		}
		node = node->next;
	}
}