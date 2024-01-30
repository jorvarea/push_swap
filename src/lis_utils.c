/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:47:16 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/30 11:16:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_moves(t_moves *moves)
{
	if (moves->a)
		free(moves->a);
	if (moves->b)
		free(moves->b);
}

static void	calculate_moves_b(t_list *b, int *moves_b)
{
	int	size;
	int	i;

	size = list_size(b);
	i = 0;
	while (i < size)
	{
		if (i <= size / 2)
			moves_b[i] = i;
		else
			moves_b[i] = -(size - i);
		i++;
	}
}

static void	calculate_moves_a(t_list *a, t_list *b, int *moves_a)
{
	t_list	*current_a;
	t_list	*current_b;
	int		size_a;
	int		i;
	int		j;

	size_a = list_size(a);
	i = 0;
	current_b = b;
	while (current_b)
	{
		j = 0;
		current_a = a;
		while (current_a && current_a->number < current_b->number)
		{
			current_a = current_a->next;
			j++;
		}
		if (j <= size_a / 2)
			moves_a[i] = j;
		else
			moves_a[i] = -(size_a - j);
		current_b = current_b->next;
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

static int	optimal_move_index(t_list **b, int *moves_a, int *moves_b)
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

static void	execute_optimal_move(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	
}

void	insert_unsorted(t_list **a, t_list **b)
{
	t_moves		moves;
	int			size_stack_b;
	int			optimal_index;

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
