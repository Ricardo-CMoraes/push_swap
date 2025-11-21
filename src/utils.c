/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:09:00 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/20 22:08:57 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char *str)
{
	ft_printf("%s\n", str);
	exit (0);
}

int	count_arg(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	free_array(char **array)
{
    int i;

    if (!array)
        return ; // Se o array já for NULL, não faz nada.

    i = 0;
    while (array[i])
    {
        free(array[i]); // 1. Libera cada string (e.g., "1", "5", "2")
        i++;
    }
    
    free(array); // 2. Libera o ponteiro do array principal (char **)
}

void free_stack(t_stack *stack)
{
	t_stack_node *current;
	t_stack_node *tmp;

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


int get_max_bits(int size)
{
	int max_val;
	int bits;

	max_val = size - 1; // O maior índice é N-1
	bits = 0;

	// Enquanto o valor máximo (índice) for maior que zero, 
	// contamos os bits necessários.
	while (max_val > 0)
	{
		max_val >>= 1; // Desloca 1 bit para a direita (divide por 2)
		bits++;
	}
	return (bits);
}


void print_stack(t_stack *stack)
{
    t_stack_node *current;

    if (!stack || !stack->head)
    {
        ft_printf("--- PILHA VAZIA ---\n");
        return;
    }

    current = stack->head;
    ft_printf("--- PILHA A (TOPO -> BASE) ---\n");
    
    // Percorre do head (topo) até a base (tail)
    while (current)
    {
        ft_printf("  Valor: %d (Index: %d)\n", current->value, current->index);
        current = current->next;
    }
    ft_printf("------------------------------\n");
}