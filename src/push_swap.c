/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:49:10 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/18 21:44:43 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	check_input(argc, argv);
	stack_a = init_stack(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
    if (!stack_b)
        return (1);
	set_stack(stack_b);
	
	// Aqui virá seu algoritmo de ordenação
    // ...
    
    // Lembre-se de liberar TUDO no final!
    // free_stack(stack_a);
    // free(stack_b);
}