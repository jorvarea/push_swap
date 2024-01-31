/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_min_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:59:52 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/31 23:02:58 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_first(t_list **a, int size_a)
{
	t_element	min;
	int			i;

	find_min(*a, &min);
	if (min.index <= size_a / 2)
	{
		i = 0;
		while (i < min.index)
		{
			rotate_stack_up(a);
			ft_printf("ra\n");
			i++;
		}
	}
	else
	{
		i = size_a - min.index;
		while (i > 0)
		{
			rotate_stack_down(a);
			ft_printf("rra\n");
			i--;
		}
	}
}
