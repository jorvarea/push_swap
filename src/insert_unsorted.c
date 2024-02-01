/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_unsorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:32:28 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 17:58:51 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_unsorted(t_list **a, t_list **b)
{
	t_moves	moves;
	int		size_stack_b;
	int		optimal_index;

	size_stack_b = list_size(*b);
	moves.a = malloc(size_stack_b * sizeof(int));
	moves.b = malloc(size_stack_b * sizeof(int));
	if (!moves.a || !moves.b)
		exit(EXIT_FAILURE);
	while (*b)
	{
		calculate_moves_b(*b, moves.b);
		calculate_moves_a(*a, *b, moves.a);
		optimal_index = optimal_move_index(b, moves.a, moves.b);
		execute_optimal_move(a, b, &moves, optimal_index);
	}
	free_moves(&moves);
}
