/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/28 17:52:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lis_ending_at_index(int *array, int *lis_ending_at, int index)
{
	int	lis_ending_at_index;
	int	i;

	lis_ending_at_index = 1;
	i = index;
	while (i >= 0)
	{
		if (array[i] < array[index])
			lis_ending_at_index = ft_max(lis_ending_at_index,
					lis_ending_at[i] + 1);
		i--;
	}
	return (lis_ending_at_index);
}

static int lis_circular_array(int *array, int *lis_ending_at, int size)
{
	int i;
	int lis;
	
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

int	longest_increasing_subsequence_algorithm(t_list *head)
{
	int	*array;
	int	*lis_ending_at;
	int lis;
	int	size;

	list2circular_array(head, &array, &size);
	if (array == NULL)
		return (-1);
	lis_ending_at = malloc(size * sizeof(int));
	if (lis_ending_at == NULL)
	{
		free(array);
		return (-1);
	}
	lis = lis_circular_array(array, lis_ending_at, size);
	free(array);
	free(lis_ending_at);
	return (lis);
}
