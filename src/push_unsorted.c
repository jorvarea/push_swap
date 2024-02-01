/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:59:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 01:01:11 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_median(t_list *a, int unsorted_size, int *lis,
		int lis_size)
{
	t_list	*current;
	int		*unsorted;
	int		median;
	int		i;

	unsorted = malloc(unsorted_size * sizeof(int));
	current = a;
	i = 0;
	while (current)
	{
		if (!array_contains(lis, lis_size, current->number))
		{
			unsorted[i] = current->number;
			i++;
		}
		current = current->next;
	}
	bubble_sort(unsorted, unsorted_size);
	median = unsorted[unsorted_size / 2];
	free(unsorted);
	return (median);
}

static void	rotate_until_next_unsorted(t_list **a, int *lis, int lis_size)
{
	int	*numbers;
	int	stack_size;
	int	i;
	int	j;

	stack_size = list_size(*a);
	list2array(*a, &numbers, stack_size);
	i = 0;
	while (array_contains(lis, lis_size, numbers[i]))
		i++;
	j = 0;
	while (array_contains(lis, lis_size, numbers[stack_size - j - 1]))
		j++;
	if (i <= j)
	{
		while (i--)
		{
			rotate_stack_up(a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (j--)
		{
			rotate_stack_down(a);
			ft_printf("rra\n");
		}
	}
	free(numbers);
}

void	push_unsorted(t_list **a, t_list **b, int *lis, int lis_size)
{
	int	unsorted_size;
	int	median;
	int	i;

	unsorted_size = list_size(*a) - lis_size;
	median = calculate_median(*a, unsorted_size, lis, lis_size);
	i = 0;
	while (i < unsorted_size)
	{
		rotate_until_next_unsorted(a, lis, lis_size);
		if ((*a)->number <= median)
		{
			push_top_stack(b, a);
			ft_printf("pb\n");
		}
		else
		{
			push_top_stack(b, a);
			ft_printf("pb\n");
			rotate_stack_up(b);
			ft_printf("rb\n");
		}
		i++;
	}
}
