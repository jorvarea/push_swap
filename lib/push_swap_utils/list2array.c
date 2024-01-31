/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:45:14 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 11:44:22 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	list2array(t_list *head, int **array, int size)
{
	t_list	*current;
	int		i;

	*array = malloc(size * sizeof(int));
	if (*array)
	{
		current = head;
		i = 0;
		while (i < size)
		{
			(*array)[i] = current->number;
			current = current->next;
			i++;
		}
	}
}
