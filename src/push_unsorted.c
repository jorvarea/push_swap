/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:59:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 23:07:46 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_moves(t_list *b, int *moves_b)
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

void	push_unsorted(t_list **a, t_list **b, int *lis, int lis_size)
{
	int	stack_len;
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
