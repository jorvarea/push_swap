/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2circular_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:31:41 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 01:50:57 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	list2circular_array(t_list *head, int **array, int stack_size)
{
	t_list	*current;
	int		i;

	*array = malloc(stack_size * 2 * sizeof(int));
	if (!*array)
		exit(EXIT_FAILURE);
	current = head;
	i = 0;
	while (i < stack_size)
	{
		(*array)[i] = current->number;
		current = current->next;
		i++;
	}
	current = head;
	while (i < stack_size * 2)
	{
		(*array)[i] = current->number;
		current = current->next;
		i++;
	}
}
