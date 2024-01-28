/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/28 17:28:22 by jorvarea         ###   ########.fr       */
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

int	longest_increasing_subsequence(t_list *head)
{
	int	*array;
	int	*lis_ending_at;
	int	lis;
	int	size;
	int	i;

	list2array(head, &array, &size);
	if (array == NULL)
		return (-1);
	lis_ending_at = malloc(size * sizeof(int));
	if (lis_ending_at == NULL)
	{
		free(array);
		return (-1);
	}
	lis = 1;
	i = 0;
	while (i < size)
	{
		lis_ending_at[i] = find_lis_ending_at_index(array, lis_ending_at, i);
		if (lis_ending_at[i] > lis)
			lis = lis_ending_at[i];
		i++;
	}
	free(array);
	free(lis_ending_at);
	return (lis);
}
