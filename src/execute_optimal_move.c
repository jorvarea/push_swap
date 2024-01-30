/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_optimal_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:49 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/30 14:05:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_plus_plus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
    
}

static void move_plus_minus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
    
}

static void move_minus_plus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
    
}

static void move_minus_minus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
    
}

void	execute_optimal_move(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
    if (moves->a[index] >= 0 && moves->b[index] >= 0)
		move_plus_plus(a, b, moves, optimal_index);
	else if (moves->a[index] >= 0 && moves->b[index] < 0)
		move_plus_minus(a, b, moves, optimal_index);
	else if (moves->a[index] < 0 && moves->b[index] >= 0)
		move_minus_plus(a, b, moves, optimal_index);
	else
		move_minus_minus(a, b, moves, optimal_index);
}