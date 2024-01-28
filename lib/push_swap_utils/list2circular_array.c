/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2circular_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:31:41 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/28 17:38:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	list2circular_array(t_list *head, int **array, int *size)
{
	t_list	*current;
	int		i;

	*size = list_size(head) * 2;
	*array = malloc(*size * sizeof(int));
	if (*array)
	{
		current = head;
		i = 0;
		while (i < *size / 2)
		{
			(*array)[i] = current->number;
			current = current->next;
			i++;
		}
        current = head;
		while (i < *size)
		{
			(*array)[i] = current->number;
			current = current->next;
			i++;
		}
	}
	else
		*size = 0;
}
