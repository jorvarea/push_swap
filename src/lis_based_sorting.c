/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_based_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/30 11:16:32 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_unsorted(t_list **a, t_list **b, int *lis, int stack_len)
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
