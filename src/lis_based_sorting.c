/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_based_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 11:45:43 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_based_sorting(t_list **a, t_list **b, int stack_len)
{
	int	*numbers;
	int	*lis;

	print_stacks(*a, *b);
	list2array(*a, &numbers, stack_len);
	lis = longest_increasing_subsequence(numbers, stack_len);
	push_unsorted(a, b, lis, stack_len);
	print_stacks(*a, *b);
	free(lis);
	insert_unsorted(a, b);
	put_min_first(a, stack_len);
	print_stacks(*a, *b);
}
