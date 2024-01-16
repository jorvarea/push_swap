/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_extract_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:10:31 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 17:37:06 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_extract_last(t_list *head)
{
	t_list	*previous;
	t_list	*current;

	current = NULL;
	if (head != NULL && head->next != NULL)
	{
		previous = head;
		current = head->next;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
	}
	return (current);
}
