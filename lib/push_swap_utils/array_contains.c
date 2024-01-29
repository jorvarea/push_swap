/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_contains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:03:48 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/29 14:14:42 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

bool	array_contains(int *array, int size, int element)
{
	int		i;
	bool	found;

	found = false;
	i = 0;
	while (i < size)
	{
		if (array[i] == element)
			found = true;
		i++;
	}
	return (found);
}
