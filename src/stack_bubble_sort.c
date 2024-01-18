/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bubble_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:02:22 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/19 00:25:58 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_bubble_sort(t_list **a)
{
	while (!is_stack_sorted(*a))
	{
		if ((*a)->number > (*a)->next->number && !is_stack_sorted((*a)->next))
        {
            swap_top_stack(a);
            ft_printf("sa\n");
        }
        if (!is_stack_sorted(*a))
        {
            rotate_stack_up(a);
            ft_printf("ra\n");
        }
	}
}
