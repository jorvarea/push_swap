/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 02:23:14 by jorvarea         ###   ########.fr       */
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
