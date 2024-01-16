/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:02:09 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 14:48:40 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	list_add_back(t_list **head, t_list *new_element)
{
	t_list	*last_element;

	if (*head == NULL)
		*head = new_element;
	else
	{
		last_element = list_last(*head);
		last_element->next = new_element;
	}
}
