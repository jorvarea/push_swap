/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:48:37 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/16 17:38:09 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_last(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL && current->next != NULL)
		current = current->next;
	return (current);
}
