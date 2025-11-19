/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:53:12 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/16 23:24:20 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_nbr(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_input(int argc, char **argv)
{
	int		i;
	long	tmp_number;
	char	**tmp_array;

	i = 0;
	if (argc == 2)
		tmp_array = ft_split(argv[1], ' ');
	else
		tmp_array = argv + 1; //??
	while (tmp_array[i])
	{
		tmp_number = ft_atoi(tmp_array[i]);
		if (tmp_number < INT_MIN || tmp_number > INT_MAX)
			error_msg("ERROR");
		if (!check_nbr(tmp_array[i]))
			error_msg("ERROR");
		if (!check_doubles(tmp_array))
			error_msg("ERROR");
		i++;
	}
	if (argc == 2)
		free_array (tmp_array);
}
