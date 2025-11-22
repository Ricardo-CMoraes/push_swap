/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rida-cos <rida-cos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:49:10 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/22 12:23:49 by rida-cos         ###   ########.fr       */
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
	set_stack_null(stack_b);
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free(stack_b);
}
// Revisar Validação da Entrada
// Passar testes da 42