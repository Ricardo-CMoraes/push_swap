/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rida-cos <rida-cos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:36:26 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/22 12:19:39 by rida-cos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit_pos;
	int	j;
	int	size;

	size = a->size;
	max_bits = get_max_bits(size);
	bit_pos = 0;
	while (bit_pos < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->head->index >> bit_pos) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		bit_pos++;
	}
}
