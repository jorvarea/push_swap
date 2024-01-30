/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_based_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/30 20:47:35 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_based_sorting(t_list **a, t_list **b, int stack_len)
{
	int	*numbers;
	int	size_numbers;
	int	*lis;

	print_stacks(*a, *b);
	list2array(*a, &numbers, &size_numbers);
	lis = longest_increasing_subsequence(numbers, size_numbers);
	push_unsorted(a, b, lis, stack_len);
	print_stacks(*a, *b);
	free(lis);
	insert_unsorted(a, b);
	put_min_first(a, size_numbers);
	print_stacks(*a, *b);
}
