/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:59:04 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 00:09:18 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

static void bubble_sort(int *array, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (array[j] > array[j + 1])
                ft_swap(&array[j], &array[j + 1]);
            j++;
        }
        i++;
    }
}

static int calculate_median(t_list *a, int unsorted_size, int *lis, int lis_size)
{
    t_list *current;
    int *unsorted;
    int median;
    int i;

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

void	push_unsorted(t_list **a, t_list **b, int *lis, int lis_size)
{
	int	unsorted_size;
    int median;
	int	i;

	unsorted_size = list_size(*a) - lis_size;
    median = calculate_median(*a, unsorted_size, lis, lis_size);
	i = 0;
	while (i < unsorted_size)
	{
		while (array_contains(lis, lis_size, (*a)->number))
		{
			rotate_stack_up(a);
			ft_printf("ra\n");
		}
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
