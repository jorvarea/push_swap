/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/29 12:06:02 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_arrays(int *array1, int *array2, int *array3)
{
	if (array1)
		free(array1);
	if (array2)
		free(array2);
	if (array3)
		free(array3);
}

static int	find_lis_ending_at_index(int *array, int *lis_ending_at, int index)
{
	int	lis_ending_at_index;
	int	i;

	lis_ending_at_index = 1;
	i = index;
	while (i >= 0)
	{
		if (array[i] < array[index] && lis_ending_at[i]
			+ 1 > lis_ending_at_index)
			lis_ending_at_index = lis_ending_at[i] + 1;
		i--;
	}
	return (lis_ending_at_index);
}

static int	lis_circular_array(int *array, int *lis_ending_at, int size)
{
	int	i;
	int	lis;

	lis = 1;
	i = 0;
	while (i < size)
	{
		lis_ending_at[i] = find_lis_ending_at_index(array, lis_ending_at, i);
		if (lis_ending_at[i] > lis)
			lis = lis_ending_at[i];
		i++;
	}
	return (lis);
}

int	longest_increasing_subsequence(t_list *head)
{
	int	*array;
	int	*lis_ending_at;
	int	*previous_in_sequence;
	int	lis;
	int	size;

	list2circular_array(head, &array, &size);
	lis_ending_at = malloc(size * sizeof(int));
	previous_in_sequence = malloc(size * sizeof(int));
	if (!array || !lis_ending_at || !previous_in_sequence)
	{
		free_arrays(array, lis_ending_at, previous_in_sequence);
		return (-1);
	}
	lis = lis_circular_array(array, lis_ending_at, size);
	free_arrays(array, lis_ending_at, previous_in_sequence);
	return (lis);
}
