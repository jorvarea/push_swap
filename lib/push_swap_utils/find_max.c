/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:31:29 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 20:35:51 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	find_max(t_list *a, t_element *max)
{
	t_list	*current;
	int		i;

	max->node = a;
	max->index = 0;
	i = 0;
	current = a;
	while (current)
	{
		if (current->number > max->node->number)
		{
			max->node = current;
			max->index = i;
		}
		current = current->next;
		i++;
	}
}
