/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_optimal_move_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:34:07 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 02:35:06 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_plus_plus(t_list **a, t_list **b, t_moves *moves,
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

void	move_plus_minus(t_list **a, t_list **b, t_moves *moves,
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

void	move_minus_plus(t_list **a, t_list **b, t_moves *moves,
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

static void	rotate_both(t_list **a, t_list **b, int i)
{
	while (i < 0)
	{
		rotate_stack_down_both(a, b);
		ft_printf("rrr\n");
		i++;
	}
}

void	move_minus_minus(t_list **a, t_list **b, t_moves *moves,
		int optimal_index)
{
	int	i;

	i = ft_max(moves->a[optimal_index], moves->b[optimal_index]);
	rotate_both(a, b, i);
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
