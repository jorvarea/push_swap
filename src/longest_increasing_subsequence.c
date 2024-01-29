/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/29 15:20:58 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arrays(t_lis_arrays *arrays, bool free_lis_array)
{
	if (arrays->numbers)
		free(arrays->numbers);
	if (arrays->lis_ending_at)
		free(arrays->lis_ending_at);
	if (arrays->previous_in_sequence)
		free(arrays->previous_in_sequence);
	if (arrays->lis && free_lis_array)
	{
		free(arrays->lis);
		arrays->lis = NULL;
	}
}

static void	retrieve_subsequence(t_lis_arrays *arrays, int lis_ending_index)
{
	int	current_index;
	int	i;

	arrays->lis[0] = arrays->numbers[lis_ending_index];
	current_index = lis_ending_index;
	i = 1;
	while (arrays->previous_in_sequence[current_index] != -1)
	{
		arrays->lis[i] = arrays->numbers[arrays->previous_in_sequence[current_index]];
		current_index = arrays->previous_in_sequence[current_index];
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
			arrays->previous_in_sequence[index] = i;
		}
		i--;
	}
	return (lis_ending_at_index);
}

static void	find_lis(t_lis_arrays *arrays)
{
	int	i;
	int	lis;
	int	lis_ending_index;

	i = 0;
	while (i < arrays->size)
	{
		arrays->previous_in_sequence[i] = -1;
		i++;
	}
	lis = 1;
	lis_ending_index = 0;
	i = 0;
	while (i < arrays->size)
	{
		arrays->lis_ending_at[i] = find_lis_ending_at_index(arrays, i);
		if (arrays->lis_ending_at[i] > lis)
		{
			lis = arrays->lis_ending_at[i];
			lis_ending_index = i;
		}
		i++;
	}
	retrieve_subsequence(arrays, lis_ending_index);
}

int	*longest_increasing_subsequence(int *numbers, int size)
{
	t_lis_arrays	arrays;

    arrays.numbers = numbers;
    arrays.size = size;
	arrays.lis_ending_at = malloc(arrays.size * sizeof(int));
	arrays.previous_in_sequence = malloc(arrays.size * sizeof(int));
	arrays.lis = malloc(arrays.size * sizeof(int));
	if (!arrays.numbers || !arrays.lis_ending_at || !arrays.previous_in_sequence
		|| !arrays.lis)
	{
		free_arrays(&arrays, true);
		return (NULL);
	}
	find_lis(&arrays);
	free_arrays(&arrays, false);
	return (arrays.lis);
}
