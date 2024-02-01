/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_selection_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:20:21 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 20:40:16 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_stack(t_list *head, int *min_pos)
{
	t_list	*current;
	int		min;
	int		i;

	current = head;
	i = 0;
	min = current->number;
	*min_pos = 0;
	while (current)
	{
		if (current->number < min)
		{
			min = current->number;
			*min_pos = i;
		}
		current = current->next;
		i++;
	}
}

static void	bring_min_top(t_list **head, int stack_len, int min_pos)
{
	if (min_pos <= stack_len / 2)
	{
		while (min_pos > 0)
		{
			rotate_stack_up(head);
			ft_printf("ra\n");
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_len)
		{
			rotate_stack_down(head);
			ft_printf("rra\n");
			min_pos++;
		}
	}
}

static void	push_sorted_stack_back(t_list **a, t_list **b)
{
	while (*b)
	{
		push_top_stack(a, b);
		ft_printf("pa\n");
	}
}

void	stack_selection_sort(t_list **a, t_list **b, int stack_len)
{
	int	min_pos;

	while (stack_len > 1 && !is_stack_sorted(*a))
	{
		find_min_stack(*a, &min_pos);
		bring_min_top(a, stack_len, min_pos);
		if (!is_stack_sorted(*a))
		{
			push_top_stack(b, a);
			ft_printf("pb\n");
			stack_len--;
		}
	}
	push_sorted_stack_back(a, b);
}
