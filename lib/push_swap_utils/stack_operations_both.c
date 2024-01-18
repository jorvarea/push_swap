/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_both.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:20:17 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 16:22:28 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	swap_top_stack_both(t_list **a, t_list **b)
{
    swap_top_stack(a);
    swap_top_stack(b);
}

void	rotate_stack_up_both(t_list **a, t_list **b)
{
    rotate_stack_up(a);
    rotate_stack_up(b);
}

void	rotate_stack_down_both(t_list **a, t_list **b)
{
    rotate_stack_down(a);
    rotate_stack_down(b);
}
