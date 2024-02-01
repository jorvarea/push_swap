/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_based_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 15:24:38 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_based_sorting(t_list **a, t_list **b, int stack_size)
{
	int	*numbers;
	int	*lis;
	int	lis_size;

	if (is_stack_reverse_sorted(*a))
	{
		swap_top_stack(a);
		ft_printf("sa\n");
	}
	list2circular_array(*a, &numbers, stack_size);
	lis = longest_increasing_subsequence(numbers, stack_size, &lis_size);
	push_unsorted(a, b, lis, lis_size);
	free(lis);
	insert_unsorted(a, b);
	put_min_first(a, stack_size);
}
