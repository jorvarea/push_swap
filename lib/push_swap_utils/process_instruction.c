/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:31:32 by jorvarea          #+#    #+#             */
/*   Updated: 2024/01/18 20:31:51 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

void	process_instruction(char *line, t_list **a, t_list **b, bool *error)
{
	*error = false;
	if (ft_strcmp(line, "sa\n") == 0)
		swap_top_stack(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_top_stack(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_top_stack_both(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		push_top_stack(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_top_stack(b, a);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_stack_up(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_stack_up(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_stack_up_both(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rotate_stack_down(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rotate_stack_down(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rotate_stack_down_both(a, b);
	else
		*error = true;
}
