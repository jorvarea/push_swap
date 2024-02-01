/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_optimal_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:49 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 17:03:36 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_optimal_move(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	if (moves->a[optimal_index] >= 0 && moves->b[optimal_index] >= 0)
		move_plus_plus(a, b, moves, optimal_index);
	else if (moves->a[optimal_index] >= 0 && moves->b[optimal_index] <= 0)
		move_plus_minus(a, b, moves, optimal_index);
	else if (moves->a[optimal_index] <= 0 && moves->b[optimal_index] >= 0)
		move_minus_plus(a, b, moves, optimal_index);
	else
		move_minus_minus(a, b, moves, optimal_index);
	push_top_stack(a, b);
	ft_printf("pa\n");
}
