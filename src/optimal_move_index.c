/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_move_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:00:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 23:00:55 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_moves(int *moves_a, int *moves_b, int index)
{
	int	min;

	if (moves_a[index] >= 0 && moves_b[index] >= 0)
		min = ft_max(moves_a[index], moves_b[index]);
	else if (moves_a[index] >= 0 && moves_b[index] < 0)
		min = moves_a[index] + ft_abs(moves_b[index]);
	else if (moves_a[index] < 0 && moves_b[index] >= 0)
		min = ft_abs(moves_a[index]) + moves_b[index];
	else
		min = ft_min(moves_a[index], moves_b[index]);
	return (min);
}

int	optimal_move_index(t_list **b, int *moves_a, int *moves_b)
{
	int	min_moves;
	int	min_tmp;
	int	min_moves_index;
	int	size;
	int	i;

	min_moves = 0;
	min_moves_index = -1;
	size = list_size(*b);
	i = 0;
	while (i < size)
	{
		min_tmp = total_moves(moves_a, moves_b, i);
		if (min_tmp < min_moves || min_moves == 0)
		{
			min_moves = min_tmp;
			min_moves_index = i;
		}
		i++;
	}
	return (min_moves_index);
}
