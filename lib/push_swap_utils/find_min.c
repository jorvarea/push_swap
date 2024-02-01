/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:17:01 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/01 20:18:08 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	find_min(t_list *a, t_element *min)
{
	t_list	*current;
	int		i;

	min->node = a;
	min->index = 0;
	i = 0;
	current = a;
	while (current)
	{
		if (current->number < min->node->number)
		{
			min->node = current;
			min->index = i;
		}
		current = current->next;
		i++;
	}
}
