/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_extract_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:51:20 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 16:45:00 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_extract_first(t_list **head)
{
	t_list	*extracted_element;
	t_list	*new_head;

	extracted_element = *head;
	if (extracted_element != NULL)
	{
		new_head = extracted_element->next;
		*head = new_head;
		extracted_element->next = NULL;
	}
	return (extracted_element);
}
