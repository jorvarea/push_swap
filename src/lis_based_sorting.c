/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_based_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 00:36:46 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_based_sorting(t_list **a, t_list **b, int stack_len)
{
	int	*numbers;
	int	*lis;
	int	lis_size;

	if (is_stack_reverse_sorted(*a))
	{
		swap_top_stack(a);
		ft_printf("sa\n");
	}
	list2array(*a, &numbers, stack_len);
	lis = longest_increasing_subsequence(numbers, stack_len, &lis_size);
	push_unsorted(a, b, lis, lis_size);
	free(lis);
	insert_unsorted(a, b);
	put_min_first(a, stack_len);
}
