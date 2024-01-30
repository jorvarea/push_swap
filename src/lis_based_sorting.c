/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_based_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/30 13:53:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_unsorted(t_list **a, t_list **b, int *lis, int stack_len)
{
	int	i;

	i = 0;
	while (i < stack_len)
	{
		if (!array_contains(lis, stack_len * 2, (*a)->number))
		{
			push_top_stack(b, a);
			ft_printf("pb\n");
		}
		else
		{
			rotate_stack_up(a);
			ft_printf("ra\n");
		}
		i++;
	}
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

void	execute_optimal_move(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
    
}

void	insert_unsorted(t_list **a, t_list **b)
{
	t_moves	moves;
	int		size_stack_b;
	int		optimal_index;

	size_stack_b = list_size(*b);
	moves.a = malloc(size_stack_b * sizeof(int));
	moves.b = malloc(size_stack_b * sizeof(int));
	if (moves.a && moves.b)
	{
		while (*b)
		{
			calculate_moves_b(*b, moves.b);
			calculate_moves_a(*a, *b, moves.a);
			optimal_index = optimal_move_index(b, moves.a, moves.b);
			execute_optimal_move(a, b, &moves, optimal_index);
		}
	}
	free_moves(&moves);
}

void	lis_based_sorting(t_list **a, t_list **b, int stack_len)
{
	int	*numbers;
	int	size_numbers;
	int	*lis;

	list2array(*a, &numbers, &size_numbers);
	lis = longest_increasing_subsequence(numbers, size_numbers);
	push_unsorted(a, b, lis, stack_len);
	free(lis);
	insert_unsorted(a, b);
}
