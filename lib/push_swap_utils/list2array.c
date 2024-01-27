/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:45:14 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/27 23:40:09 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	list2array(t_list *head, int **array, int *size)
{
	t_list	*current;
	int		i;

	*size = list_size(head);
	*array = malloc(*size * sizeof(int));
	if (*array)
	{
		current = head;
		i = 0;
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
