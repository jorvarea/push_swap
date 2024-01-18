/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:19:33 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 23:18:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"
#include "ft_printf.h"

void find_min(t_list *head, int *min_pos)
{
	t_list *current;
	int min;
	int i;

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

void bring_min_top(t_list **head, int stack_len, int min_pos)
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
		while(min_pos < stack_len)
		{
			rotate_stack_down(head);
			ft_printf("rra\n");
			min_pos++;
		}
	}
}

void push_sorted_stack_back(t_list **a, t_list **b)
{
	while (*b)
	{
		push_top_stack(a, b);
		ft_printf("pa\n");
	}
}

void stack_selection_sort(t_list **a, t_list **b, int stack_len)
{
	int min_pos;
	
	while (stack_len > 0)
	{
		find_min(*a, &min_pos);
		bring_min_top(a, stack_len, min_pos);
		push_top_stack(b, a);
		ft_printf("pb\n");
		stack_len--;
	}
	push_sorted_stack_back(a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	initialize_stacks(argc, argv, &a, &b);
	if (a != NULL)
		stack_selection_sort(&a, &b, argc - 1);
	clear_list(&a);
	clear_list(&b);
	return (0);
}
