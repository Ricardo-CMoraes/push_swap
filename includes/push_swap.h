/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:39:55 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/16 23:07:15 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483647

typedef struct s_stack_node
{
	int					value; // Valor original (e.g., -5, 100)
	int					index; // Posição ordenada (0, 1, 2...)
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head; // Topo da pilha
	t_stack_node	*tail; // Base da pilha
	int				size;
}	t_stack;

#endif