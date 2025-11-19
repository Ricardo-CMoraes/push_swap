/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:09:00 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/16 23:24:25 by rdcm             ###   ########.fr       */
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