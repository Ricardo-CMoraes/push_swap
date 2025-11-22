/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rida-cos <rida-cos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:09:00 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/22 12:23:00 by rida-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char *str)
{
	ft_printf("%s\n", str);
	exit (0);
}

void	set_init_stack(t_stack *stack, t_stack_node *node)
{
	stack->head = node;
	stack->tail = node;
	node->next = NULL;
	node->prev = NULL;
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
}

int	get_max_bits(int size)
{
	int	max_val;
	int	bits;

	max_val = size - 1;
	bits = 0;
	while (max_val > 0)
	{
		max_val >>= 1;
		bits++;
	}
	return (bits);
}
