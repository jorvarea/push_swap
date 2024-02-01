/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:19:45 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 12:44:47 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	find_lis(t_lis_arrays *arrays, int *lis_size)
{
	int	i;
	int	lis_ending_index;

	i = 0;
	while (i < arrays->size)
		arrays->previous[i++] = -1;
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
