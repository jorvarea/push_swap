/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_optimal_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:03:49 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 11:37:35 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_plus_plus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	int	i;

	i = 0;
	while (i < moves->a[optimal_index] && i < moves->b[optimal_index])
	{
		rotate_stack_up_both(a, b);
		ft_printf("rr\n");
		i++;
	}
	if (moves->a[optimal_index] > moves->b[optimal_index])
	{
		while (i++ < moves->a[optimal_index])
		{
			rotate_stack_up(a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (i++ < moves->b[optimal_index])
		{
			rotate_stack_up(b);
			ft_printf("rb\n");
		}
	}
}

static void	move_plus_minus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < moves->a[optimal_index])
	{
		rotate_stack_up(a);
		ft_printf("ra\n");
		i++;
	}
	j = moves->b[optimal_index];
	while (j < 0)
	{
		rotate_stack_down(b);
		ft_printf("rrb\n");
		j++;
	}
}

static void	move_minus_plus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	int	i;
	int	j;

	i = moves->a[optimal_index];
	while (i < 0)
	{
		rotate_stack_down(a);
		ft_printf("rra\n");
		i++;
	}
	j = 0;
	while (j < moves->b[optimal_index])
	{
		rotate_stack_up(b);
		ft_printf("rb\n");
		j++;
	}
}

static void	move_minus_minus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	int	i;

	i = ft_max(moves->a[optimal_index], moves->b[optimal_index]);
	while (i < 0)
	{
		rotate_stack_down_both(a, b);
		ft_printf("rrr\n");
		i++;
	}
	i = ft_min(moves->a[optimal_index], moves->b[optimal_index])
		- ft_max(moves->a[optimal_index], moves->b[optimal_index]);
	if (moves->a[optimal_index] < moves->b[optimal_index])
	{
		while (i++ < 0)
		{
			rotate_stack_down(a);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (i++ < 0)
		{
			rotate_stack_down(b);
			ft_printf("rrb\n");
		}
	}
}

void	execute_optimal_move(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	if (moves->a[optimal_index] >= 0 && moves->b[optimal_index] >= 0)
		move_plus_plus(a, b, moves, optimal_index);
	else if (moves->a[optimal_index] >= 0 && moves->b[optimal_index] < 0)
		move_plus_minus(a, b, moves, optimal_index);
	else if (moves->a[optimal_index] < 0 && moves->b[optimal_index] >= 0)
		move_minus_plus(a, b, moves, optimal_index);
	else
		move_minus_minus(a, b, moves, optimal_index);
	push_top_stack(a, b);
	ft_printf("pa\n");
}
