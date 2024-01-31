/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sorting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:32:28 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 12:34:46 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_unsorted(t_list **a, t_list **b, int *lis, int lis_size)
{
	int stack_len;
	int	i;

	stack_len = list_size(*a);
	i = 0;
	while (i < stack_len)
	{
		if (!array_contains(lis, lis_size, (*a)->number))
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

void	put_min_first(t_list **a, int size_a)
{
	t_element	min;
	int			i;

	find_min(*a, &min);
	if (min.index <= size_a / 2)
	{
		i = 0;
		while (i < min.index)
		{
			rotate_stack_up(a);
			ft_printf("ra\n");
			i++;
		}
	}
	else
	{
		i = size_a - min.index;
		while (i > 0)
		{
			rotate_stack_down(a);
			ft_printf("rra\n");
			i--;
		}
	}
}
