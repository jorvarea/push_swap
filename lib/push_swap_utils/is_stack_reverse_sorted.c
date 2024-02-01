/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_reverse_sorted.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:35:10 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 20:33:12 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

bool	is_stack_reverse_sorted(t_list *head)
{
	t_list		*previous;
	t_list		*current;
	t_element 	max;
	bool		is_reverse_sorted;

	is_reverse_sorted = true;
	find_max(head, &max);
	previous = max.node;
	if (max.node->next != NULL)
		current = max.node->next;
	else
		current = head;
	while (current != max.node && is_reverse_sorted)
	{
		if (previous->number < current->number)
			is_reverse_sorted = false;
		previous = current;
		current = current->next;
		if (current == NULL)
			current = head;
	}
	return (is_reverse_sorted);
}
