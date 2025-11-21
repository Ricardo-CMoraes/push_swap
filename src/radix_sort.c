/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:36:26 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/20 23:58:47 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_stack *a, t_stack *b)
{
    int max_bits;
    int bit_pos; // i é o contador de bits (0, 1, 2, ...)
    int j; // j é o contador de elementos
    int size;

    size = a->size;
    max_bits = get_max_bits(size); // Número total de iterações
    bit_pos = 0;
    while (bit_pos < max_bits) // Loop pelos bits (Ex: 0 até 8)
    {
        j = 0;
        while (j < size) // Loop pelos elementos (N vezes)
        {
            // Verifica o i-ésimo bit do índice do elemento no topo de A.
            // O operador '&' verifica se o bit i está "ligado" (1) ou "desligado" (0).
            if (((a->head->index >> bit_pos) & 1) == 0)
            {
                // Bit é 0: move para a Pilha B (pb)
                pb(a, b);
            }
            else
            {
                // Bit é 1: move para a base de A (ra)
                ra(a);
            }
            j++;
        }

        // --- FASE DE RETORNO ---
        // Todos os elementos com bit 'i' = 0 estão em B.
        // Todos os elementos com bit 'i' = 1 estão em A (mas rotacionados).
        
        // Move TUDO de B de volta para A (pa)
        while (b->size > 0)
        {
            pa(a, b);
        }
        bit_pos++; // Avança para o próximo bit
    }
}

void sort(t_stack *stack_a, t_stack *stack_b)
{
	t_discretized *tmp_array;

	tmp_array = create_sorted_array(stack_a->head, stack_a->size);
	fill_index(stack_a, tmp_array);
	free(tmp_array);
	radix_sort(stack_a, stack_b);
}