/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:05:08 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 17:07:30 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_top_stack(t_list **head)
{
	t_list	*current_head;
	t_list	*new_head;

	if (list_size(*head) >= 2)
	{
		current_head = *head;
		new_head = current_head->next;
		current_head->next = new_head->next;
		new_head->next = *head;
		*head = new_head;
	}
}

void	push_top_stack(t_list **dest_head, t_list **src_head)
{
	t_list	*extracted_element;

	if (list_size(*src_head) > 0)
	{
		extracted_element = list_extract_first(src_head);
		list_add_front(dest_head, extracted_element);
	}
}

void	rotate_stack_up(t_list **head)
{
	t_list	*extracted_element;

	if (list_size(*head) >= 2)
	{
		extracted_element = list_extract_first(head);
		list_add_back(head, extracted_element);
	}
}

void	rotate_stack_down(t_list **head)
{
	t_list	*last_element;

	if (list_size(*head) >= 2)
	{
		last_element = list_extract_last(*head);
		list_add_front(head, last_element);
	}
}
