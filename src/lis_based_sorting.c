/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_based_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:23:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/29 21:14:23 by jorvarea         ###   ########.fr       */
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

static void	calculate_moves_b(t_list *b, int **moves_b)
{
	int	size;
	int	i;

	size = list_size(b);
	*moves_b = malloc(size * sizeof(int));
	if (*moves_b)
	{
		i = 0;
		while (i < size)
		{
			if (i <= size / 2)
				(*moves_b)[i] = i;
			else
				(*moves_b)[i] = -(size - i);
			i++;
		}
	}
}

static void	calculate_moves_a(t_list *a, t_list *b, int **moves_a)
{
	t_list	*current_a;
	t_list	*current_b;
	int		size_a;
	int		i;
	int		j;

	*moves_a = malloc(list_size(b) * sizeof(int));
    if (*moves_a)
    {
        size_a = list_size(a);
        i = 0;
        current_b = b;
        while (current_b)
        {
            j = 0;
            current_a = a;
            while (current_a && current_a->number < current_b->number)
            {
                current_a = current_a->next;
                j++;
            }
            if (j <= size_a / 2)
                (*moves_a)[i] = j;
            else
                (*moves_a)[i] = -(size_a - j);
            current_b = current_b->next;
            i++;
        }
    }
}

static void	insert_unsorted(t_list **a, t_list **b)
{
	int	*moves_a;
	int	*moves_b;

	calculate_moves_b(*b, &moves_b);
	calculate_moves_a(*a, *b, &moves_a);
    print_stacks(*a, *b);
    for (int i = 0; i < list_size(*b); i++)
        ft_printf("%d, ", moves_a[i]);
    ft_printf("\n");
    for (int i = 0; i < list_size(*b); i++)
        ft_printf("%d, ", moves_b[i]);
    ft_printf("\n");
    free(moves_a);
    free(moves_b);
}

void	lis_based_sorting(t_list **a, t_list **b, int stack_len)
{
	int	*numbers;
	int	size_numbers;
	int	*lis;

	list2array(*a, &numbers, &size_numbers);
	lis = longest_increasing_subsequence(numbers, size_numbers);
	push_unsorted(a, b, lis, stack_len);
	insert_unsorted(a, b);
}
