/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:04:41 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 14:13:10 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clear_list(t_list **head)
{
	t_list	*list_element;
	t_list	*temp;

	list_element = *head;
	while (list_element != NULL)
	{
		temp = list_element->next;
		free(list_element);
		list_element = temp;
	}
	*head = NULL;
}
