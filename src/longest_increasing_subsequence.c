/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 02:14:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arrays(t_lis_arrays *arrays)
{
	if (arrays->numbers)
		free(arrays->numbers);
	if (arrays->lis_ending_at)
		free(arrays->lis_ending_at);
	if (arrays->previous)
		free(arrays->previous);
}

static void	retrieve_subsequence(t_lis_arrays *arrays, int lis_ending_index)
{
	int	current_i;
	int	i;

	arrays->lis[0] = arrays->numbers[lis_ending_index];
	current_i = lis_ending_index;
	i = 1;
	while (arrays->previous[current_i] != -1)
	{
		arrays->lis[i] = arrays->numbers[arrays->previous[current_i]];
		current_i = arrays->previous[current_i];
		i++;
	}
}

static int	find_lis_ending_at_index(t_lis_arrays *arrays, int index)
{
	int	lis_ending_at_index;
	int	i;

	lis_ending_at_index = 1;
	i = index;
	while (i >= 0)
	{
		if (arrays->numbers[i] < arrays->numbers[index]
			&& arrays->lis_ending_at[i] + 1 > lis_ending_at_index)
		{
			lis_ending_at_index = arrays->lis_ending_at[i] + 1;
			arrays->previous[index] = i;
		}
		i--;
	}
	return (lis_ending_at_index);
}

static void	find_lis(t_lis_arrays *arrays, int *lis_size)
{
	int	i;
	int	lis_ending_index;

	i = 0;
	while (i < arrays->size)
	{
		arrays->previous[i] = -1;
		i++;
	}
	*lis_size = 1;
	lis_ending_index = 0;
	i = 0;
	while (i < arrays->size)
	{
		arrays->lis_ending_at[i] = find_lis_ending_at_index(arrays, i);
		if (arrays->lis_ending_at[i] > *lis_size)
		{
			*lis_size = arrays->lis_ending_at[i];
			lis_ending_index = i;
		}
		i++;
	}
	retrieve_subsequence(arrays, lis_ending_index);
}

int	*longest_increasing_subsequence(int *numbers, int stack_size, int *lis_size)
{
	t_lis_arrays	arrays;

	arrays.numbers = numbers;
	arrays.size = stack_size;
	arrays.lis_ending_at = malloc(arrays.size * sizeof(int));
	arrays.previous = malloc(arrays.size * sizeof(int));
	arrays.lis = malloc(arrays.size * sizeof(int));
	if (!arrays.numbers || !arrays.lis_ending_at || !arrays.previous
		|| !arrays.lis)
		exit(EXIT_FAILURE);
	find_lis(&arrays, lis_size);
	free_arrays(&arrays);
	return (arrays.lis);
}
